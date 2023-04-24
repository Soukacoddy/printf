#include "main.h"

/**
 * get_size - handles length modifiers for printf
 * @format: input format string
 * @i: pointer to the current index in format string
 *
 * Return: the size corresponding to the length modifier
 */

int get_size(const char *format, int *i)
{
	int counter = *i + 1;
	int size = 0;

	if (format[counter] == 'l')
		size = 2;
	else if (format[counter] == 'h')
		size = 1;

	if (size == 0)
		*i = counter - 1;
	else
		*i = counter;

	return (size);
}
