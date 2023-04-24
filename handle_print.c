#include "main.h"

/**
 * handle_print - chooses the correct function to handle the format specifier
 * @specifier_value: pointer to format specifier
 * @index: pointer to index of current format specifier
 * @arr: list of arguments passed to function
 * @temp: buffer to store formatted string
 * @flgs: flags to modify formatting
 * @wth: minimum width of field
 * @prc: precision specifier
 * @s: length modifier
 *
 * Return: number of characters written
 */

int  handle_print(const char *specifier_value, int *index, va_list arr,
	char temp[], int flgs, int wth, int prc, int s)

{
	int i, error = 0;

	fdatat_f function_arr[] = {
	{'c', write_char_function}, {'s', write_str}, {'%', write_per},
	{'d', write_int}, {'i', write_int}, {'b', write_b}, {'u', write_uns},
	{'o', write_oct}, {'x', write_hex}, {'X', write_hex_upper},
	{'S', write_unprintable}, {'p', write_pointer}, {'r', write_rev},
	{'R', write_rot13}, {'\0', NULL}
	};


	for (i = 0; function_arr[i].char_f != '\0'; i++)
		if (specifier_value[*index] == function_arr[i].char_f)
			return (function_arr[i].function(arr, temp, flgs, wth, prc, s));

	if (function_arr[i].char_f == '\0')
	{
		if (specifier_value[*index] == '\0')
			return (-1);
		error += write(1, "%%", 1);

		if (specifier_value[*index - 1] == ' ')
			error += write(1, " ", 1);
		else if (wth)
		{
			--(*index);
			while (specifier_value[*index] != ' ' && specifier_value[*index] != '%')
				--(*index);
			if (specifier_value[*index] == ' ')
				--(*index);
			return (1);
		}
		error += write(1, &specifier_value[*index], 1);
		return (error);
	}
	return (-1);
}
