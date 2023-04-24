#include "main.h"

/**
 * get_width - extracts the width from the format string
 *
 * @format: pointer to the format string
 * @i: pointer to the current position in the format string
 * @arr: variable argument list
 *
 * Return: the width extracted from the format string
 */

int get_width(const char *format, int *i, va_list arr)
{
	int counter;
	int width = 0;

	for (counter = *i + 1; format[counter] != '\0'; counter++)
	{
		if (is_digit(format[counter]))
		{
			width *= 10;
			width += format[counter] - '0';
		}
		else if (format[counter] == '*')
		{
			counter++;
			width = va_arg(arr, int);
			break;
		}
		else
			break;
	}

	*i = counter - 1;

	return (width);
}
