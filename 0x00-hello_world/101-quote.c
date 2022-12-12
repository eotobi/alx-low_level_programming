#include <stdio.h>

/**
 * main - Entry point
 *
 * filedes is of type int
 *
 * buf is of type character
 *
 * nbyte is of type insigned integer
 *
 * Return: Always 1 (Success)
 */

int write(int filedes, const char *buf, unsigned int nbyte);

int main(void)

{
	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
	return (1);

}


