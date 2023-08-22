#include "main.h"

/**
 * * csize - Calculates the size of characters
 * * @format: string where output is stored
 * * @i: List of arguments to be printed.
 * *
 * * Return: Precision.
 * */
int csize(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

