#include "main.h"

/**
* _isalpha - a function that checks for alphabetic character
* @n: single letter input
* Return: 1 if n is a letter (lower or uppercase), otherwise returns 0
*/
int _isalpha(int n)
{
	if (((n >= 'a') && (n <= 'z')) || ((n >= 'A') && (n <= 'Z')))
		return (1);
	else
		return (0);

}
