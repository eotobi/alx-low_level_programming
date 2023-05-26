#include <stdio.h>
#include <stdlib.h>

/**
 * rand - Override the rand() function to always return the winning numbers
 */
int rand(void)
{
    return 9;
}

