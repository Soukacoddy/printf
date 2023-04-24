#include "main.h"

/**
 * append_hexa_code - Appends the hexa representation
 *	of an ascii code to a string.
 *
 * @ascii_code: The ascii code to convert to hexa.
 * @temp: The string where the hexa code will be appended.
 * @i: The index in the string where the hexa code should be written.
 *
 * Return: The number of characters appended to the string.
 */
int append_hexa_code(char ascii_code, char temp[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	temp[i++] = '\\';
	temp[i++] = 'x';

	temp[i++] = map_to[ascii_code / 16];
	temp[i] = map_to[ascii_code % 16];

	return (3);
}
