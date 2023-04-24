#include "main.h"
/**
 * _write_char - Writes a single character to stdout
 * @c: The character to print
 * @arr: The character buffer to store the output
 * @f: The formatting flags
 * @w: The field width
 * @p: The precision
 * @s: The size of the data type
 *
 * Return: The number of characters written to stdout
 */

int _write_char(char c, char arr[],
	int f, int w, int p, int s)
{
	int i = 0;
	char text = ' ';
	int tmp_size = 1024;

	(void)(p);
	(void)(s);

	if (f & 4)
		text = '0';

	arr[i++] = c;
	arr[i] = '\0';

	if (w > 1)
	{
		arr[tmp_size - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			arr[tmp_size - i - 2] = text;

	if (f & 1)
		return (write(1, &arr[0], 1) +
			write(1, &arr[tmp_size - i - 1], w - 1));
	else
		return (write(1, &arr[tmp_size - i - 1], w - 1) +
			write(1, &arr[0], 1));
	}

	return (write(1, &arr[0], 1));
}

/**
 * write_num - Write a number using a buffer
 * @cont: Index at which the number starts on the buffer
 * @temp: Buffer
 * @f: Flags
 * @w: Width
 * @prec: Precision specifier
 * @len: Number length
 * @txt: Padding character
 * @app_c: Extra character
 *
 * Return: Number of printed characters.
 */

int write_num(int cont, char temp[], int f, int w, int prec,
	int len, char txt, char app_c)
{
	int i, padd_start = 1, tmp_size = 1024;

	if (prec == 0 && cont == tmp_size - 2 && temp[cont] == '0' && w == 0)
		return (0); /* printf(".0d", 0) no char is printed */
	if (prec == 0 && cont == tmp_size - 2 && temp[cont] == '0')
		temp[cont] = txt = ' ';
	if (prec > 0 && prec < len)
		txt = ' ';
	while (prec > len)
		temp[--cont] = '0', len++;
	if (app_c != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			temp[i] = txt;
		temp[i] = '\0';
		if (f & 1 && txt == ' ')
		{
			if (app_c)
				temp[--cont] = app_c;
			return (write(1, &temp[cont], len) + write(1, &temp[1], i - 1));
		}
		else if (!(f & 1) && txt == ' ')
		{
			if (app_c)
				temp[--cont] = app_c;
			return (write(1, &temp[1], i - 1) + write(1, &temp[cont], len));
		}
		else if (!(f & 1) && txt == '0')
		{
			if (app_c)
				temp[--padd_start] = app_c;
			return (write(1, &temp[padd_start], i - padd_start) +
				write(1, &temp[cont], len - (1 - padd_start)));
		}
	}
	if (app_c)
		temp[--cont] = app_c;
	return (write(1, &temp[cont], len));
}



/**
 * write_number - Prints a string
 * @is_ntv: Indicates if the number is negative
 * @con: Starting index of the buffer
 * @temp: Buffer array to handle print
 * @f: Calculates active flags
 * @w: Width specifier
 * @prc: Precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_ntv, int con, char temp[],
	int f, int w, int prc, int s)
{
	int tmp_size = 1024;
	int length = tmp_size - con - 1;
	char padd = ' ', extra_ch = 0;

	(void)(s);

	if ((f & 4) && !(f & 1))
		padd = '0';
	if (is_ntv)
		extra_ch = '-';
	else if (f & 2)
		extra_ch = '+';
	else if (f & 16)
		extra_ch = ' ';

	return (write_num(con, temp, f, w, prc, length, padd, extra_ch));
}

/**
 * write_unsgnd - Writes an unsigned integer into a
 *	buffer with certain formatting options.
 *
 * @is_ntv: An integer flag indicating whether the
 *	number being written is negative or not.
 * @con: The index in the buffer where the number
 *	should start being written.
 * @temp: The buffer where the number will be written.
 * @f: A bitmask of formatting options.
 * @w: The minimum width of the output string.
 * @prc: The minimum number of digits to write.
 * @s: The size of the buffer.
 *
 * Return: The number of characters written, or -1 on error.
 */
int write_unsgnd(int is_ntv, int con, char temp[],
	int f, int w, int prc, int s)
{
	int tmp_size = 1024;
	int length = tmp_size - con - 1, i = 0;
	char padd = ' ';

	(void)(is_ntv);
	(void)(s);

	if (prc == 0 && con == tmp_size - 2 && temp[con] == '0')
		return (0);

	if (prc > 0 && prc < length)
		padd = ' ';

	while (prc > length)
	{
		temp[--con] = '0';
		length++;
	}

	if ((f & 4) && !(f & 1))
		padd = '0';

	if (w > length)
	{
		for (i = 0; i < w - length; i++)
			temp[i] = padd;

		temp[i] = '\0';

		if (f & 1)
			return (write(1, &temp[con], length) + write(1, &temp[0], i));
		else
			return (write(1, &temp[0], i) + write(1, &temp[con], length));
	}

	return (write(1, &temp[con], length));
}

