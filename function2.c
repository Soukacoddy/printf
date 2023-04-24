#include "main.h"

/**
 * write_rev - Writes a reverse string to a temporary buffer.
 * @arr: List of arguments
 * @temp: Temporary buffer to handle write
 * @f: Calculates active flags
 * @w: Width specification
 * @prc: Precision specification
 * @s: Size specifier
 * Return: Number of characters written
 */

int write_rev(va_list arr, char temp[], int f, int w, int prc, int s)
{
	char *str;
	int i, count = 0;

	(void)f;
	(void)w;
	(void)s;

	str = va_arg(arr, char *);

	if (str == NULL)
	{
		(void)prc;
		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		temp[count] = str[i];
		count++;
	}

	write(1, temp, count);

	return (count);
}

/**
 * write_rot13 - Writes a string in rot13 to a temporary buffer.
 * @arr: List of arguments
 * @temp: Temporary buffer to handle write
 * @f: Calculates active flags
 * @w: Width specification
 * @prc: Precision specification
 * @s: Size specifier
 * Return: Number of characters written
 */
int write_rot13(va_list arr, char temp[], int f, int w, int prc, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arr, char *);

	(void)f;
	(void)w;
	(void)prc;
	(void)s;

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				temp[count] = x;
				count++;
				break;
			}
		}
		if (!in[j])
		{
			temp[count] = str[i];
			count++;
		}
	}

	write(1, temp, count);

	return (count);
}


/**
 * write_unprintable - Writes ascii codes in hexa of non printable chars
 * @arr: Lista of arguments
 * @temp: Buffer array to handle print
 * @f: Calculates active flags
 * @w: get width
 * @prc: Precision specification
 * @s: Size specifier
 *
 * Return: Number of chars printed
 */
int write_unprintable(va_list arr, char temp[],
	int f, int w, int prc, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(arr, char *);

	(void)(f);
	(void)(w);
	(void)(prc);
	(void)(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			temp[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], temp, i + offset);

		i++;
	}

	temp[i + offset] = '\0';

	return (write(1, temp, i + offset));
}

/**
 * write_pointer - Writes the value of a pointer variable to a buffer
 * @arr: List of arguments
 * @temp: Buffer array to handle write
 * @f: Calculates active flags
 * @w: get width
 * @prc: Precision specification
 * @s: Size specifier
 * Return: Number of chars written.
 */
int write_pointer(va_list arr, char temp[], int f, int w, int prc, int s)
{
	char main_char = 0, padd = ' ';
	int tmp_size = 1024, cont = tmp_size - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(arr, void *);

	(void)(w);
	(void)(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	temp[tmp_size - 1] = '\0';
	(void)(prc);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		temp[cont--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((f & 4) && !(f & 1))
		padd = '0';
	if (f & 2)
		main_char = '+', length++;
	else if (f & 16)
		main_char = ' ', length++;

	cont++;


	return (_write_pointer(temp, cont, length, w, f,
		padd, main_char, padd_start));
}
