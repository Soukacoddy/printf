#include "main.h"


/**
 * is_digit - checks if a character is a digit
 *
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_unsgnd - converts an unsigned
 *	long integer to a smaller size
 *
 * @num: the unsigned long integer to convert
 * @size: the desired size of the converted
 *	integer (2 or 4 bytes)
 *
 * Return: the converted integer
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 2)
		return ((unsigned short)num);

	return ((unsigned int)num);
}


/**
 * convert_size_number - converts a long integer to a smaller size
 *
 * @num: the long integer to convert
 * @size: the desired size of the converted integer (1 or 2 bytes)
 *
 * Return: the converted integer
 */


long int convert_size_number(long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((short)num);

	return ((int)num);
}


/**
 * is_printable - checks if a character is printable
 *
 * @c: the character to check
 *
 * Return: 1 if c is printable, 0 otherwise
 */


int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
