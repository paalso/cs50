#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
    	printf("Usage: ./filter_dict filename word_length\n");
    	printf("The program filters wordlist by word's length\n");
    	return 1;
    }

	const char *filename = argv[1];
	int word_length = atoi(argv[2]);

	char word[SIZE];

	FILE *infile = fopen(filename, "r");

    if (infile == NULL) {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

	while(! feof(infile)) {
		fscanf(infile, "%s", word);
		if (strlen(word) == word_length) {
			printf("%s\n",word);
		}
	}

	fclose(infile);
}
