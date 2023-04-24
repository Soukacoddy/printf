#include "main.h"
/**
 * get_flags - handles flags in format string
 *
 * @format: format string
 * @i: pointer to current index in format string
 *
 * Return: flags
 */

int get_flags(const char *format, int *i)
{

	int j, counter;
	int flags = 0;
	const char char_flags_arr[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_arr[] = {1, 2, 4, 8, 16, 0};

	for (counter = *i + 1; format[counter] != '\0'; counter++)
	{
		for (j = 0; char_flags_arr[j] != '\0'; j++)
			if (format[counter] == char_flags_arr[j])
			{
				flags |= flags_arr[j];
				break;
			}

		if (char_flags_arr[j] == 0)
			break;
	}

	*i = counter - 1;

	return (flags);
}
