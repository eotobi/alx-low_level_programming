#include <stdio.h>
#include <string.h>

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array containing the command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    /* Extract the program name from the provided path */
    char *programName = strrchr(argv[0], '/');

    if (programName == NULL)
        programName = argv[0];
    else
        programName++;

    /* Print the program name */
    printf("%s\n", programName);

    return 0;
}
