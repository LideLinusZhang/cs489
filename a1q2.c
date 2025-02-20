#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char **argv)
{
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr, "File open failed.\n");
        return -1;
    }

    FILE *pipe = popen("wc -c", "w");

    int c;
    while ((c = fgetc(file)) != NULL)
    {
        fputc(c, pipe);
    }

    fclose(file);
    pclose(pipe);

    return 0;
}