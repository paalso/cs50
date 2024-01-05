/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 *
 * https://docs.cs50.net/problems/recover/recover.html
 * https://cdn.cs50.net/2016/spring/psets/4/pset4/pset4.html#recover
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t  BYTE;


#define  BUF_SIZE 512
#define  CHECK_JPG_SEGMENT_SIZE 4
#define  FILE_NAME_LEN   7

const int jpg_start1[] = {0xff, 0xd8, 0xff, 0xe0};
const int jpg_start2[] = {0xff, 0xd8, 0xff, 0xe1};

_Bool check_jpgstart(BYTE *buffer);

int main()
{
    const char infile[] = "card.raw";
    int counter = 0;
    FILE *inptr, *outptr;
    _Bool successfully_read;

    BYTE *block = (BYTE *)malloc(BUF_SIZE * sizeof(BYTE));

    if ((inptr = fopen(infile, "r")) == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // Search for the first fragment that characterizes the beginning of the jpg file

    do
    {
        fread(block, BUF_SIZE, 1, inptr);
    }
    while (!check_jpgstart(block));

    // Since we've already read the block, we have to get back to its beginning.
    fseek(inptr, -BUF_SIZE, SEEK_CUR);

    // We're starting the actual recovery process
    do
    {
        // Important point: below (line 80) need to check that a block has been read
        // correctly.
        // Otherwise there will be problems with reading the last block.
        // More precisely with writing the last block to the target file (it will be written twice)
        successfully_read = fread(block, BUF_SIZE, 1, inptr);
        if (check_jpgstart(block))
        {
            if (counter)
            {
                fclose(outptr);
            }
            char *outfile = malloc((FILE_NAME_LEN + 1) * sizeof(char));
            sprintf(outfile, "%03d.jpg", counter);
            if ((outptr = fopen(outfile, "w")) == NULL)
            {
                fprintf(stderr, "Could not open %s.\n", outfile);
                return 2;
            }
            free(outfile);
            counter += 1;
        }
        if (successfully_read)
        {
            fwrite(block, BUF_SIZE, 1, outptr);
        }
    }
    while (!feof(inptr));
    // fwrite(block, BUF_SIZE, 1, outptr);
    free(block);
    fclose(outptr);
    fclose(inptr);
}

// ---------------------------------------------------------------
_Bool check_jpgstart(BYTE *buffer)
{
    for (int i = 0; i < CHECK_JPG_SEGMENT_SIZE; ++i)
    {
        if ((buffer[i] != jpg_start1[i]) && (buffer[i] != jpg_start2[i]))
        {
            return false;
        }
    }
    return true;
}