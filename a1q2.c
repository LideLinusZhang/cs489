#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 256

int isPathValid(char *path)
{
    const char *ok_chars = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "1234567890_-.@/";
    const char *end = path + strlen(path);

    if (path + strspn(cp, ok_chars) != end)
        return 0;
    
    return 1;
}

// This program prints the size of a specified file in bytes
int main(int argc, char **argv)
{
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    if (!isPathValid(argv[1]))
    {
        fprintf(stderr, "File address contains invalid characters.\n");
        return -1;
    } 

    char cmd[BUFSIZE] = "wc -c < ";
    strncat(cmd, argv[1], BUFSIZE - 9);
    system(cmd);
}