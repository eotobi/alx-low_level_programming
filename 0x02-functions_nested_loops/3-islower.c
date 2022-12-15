#include "main.h"

/**
* _islower - a function that checks for lowercase character
*
* @n: single letter input
* Return: 1 if int n is lowercase, 0 if otherwise
*/
int _islower(int n)
{
	if (n >= 'a' && n <= 'z')
		return (1);
	else
		return (0);
}
