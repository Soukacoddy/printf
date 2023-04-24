#include "main.h"




/**
 * _printf - custom implementation of printf function
 * @format: format string containing format specifiers
 *
 * Return: number of characters printed, or -1 if error
 */


int _printf(const char *format, ...)
{
	va_list list;
	int i, main_size = 0, to_write = 0, chars_to_write = 0, temp_buffer = 0;
	int tmp_size = 1024, flags, width, precision;
	char temp[1024];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			temp[temp_buffer++] = format[i];
			if (temp_buffer == tmp_size)
				write_char(temp, &temp_buffer);
			chars_to_write++;
		}
		else
		{
			write_char(temp, &temp_buffer);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			main_size = get_size(format, &i);
			++i;
			to_write = handle_print(format, &i, list, temp,
					     flags, width, precision, main_size);
			if (to_write == -1)
				return (-1);
			chars_to_write += to_write;
		}
	}

	write_char(temp, &temp_buffer);
	va_end(list);

	return (chars_to_write);
}
