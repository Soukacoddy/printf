#include "main.h"
/**
 * get_precision - handles precision formatting
 * @format: pointer to format string
 * @i: pointer to index variable
 * @arr: va_list containing arguments
 *
 * Return: precision value
 */

int get_precision(const char *format, int *i, va_list arr)
{
	int counter = *i + 1;
	int precision = -1;

	if (format[counter] != '.')
		return (precision);

	precision = 0;

	for (counter += 1; format[counter] != '\0'; counter++)
	{
		if (is_digit(format[counter]))
		{
			precision *= 10;
			precision += format[counter] - '0';
		}
		else if (format[counter] == '*')
		{
			counter++;
			precision = va_arg(arr, int);
			break;
		}
		else
			break;
	}

	*i = counter - 1;

	return (precision);
}
