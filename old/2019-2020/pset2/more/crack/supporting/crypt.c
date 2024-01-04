#define _XOPEN_SOURCE
#include <unistd.h>	
#include <stdio.h>
#include <stdbool.h>
// #include <crypt.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
    	printf("Usage: ./crack password salt\n");
    	return 1;
    }

    const char *password = argv[1];
    const char *salt = argv[2];
    printf("%s\n", crypt(password, salt));
    return 0;
}