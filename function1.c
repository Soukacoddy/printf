#include "main.h"
/**
 * write_uns - writes an unsigned integer to a buffer
 * @arr: va_list containing the argument to print
 * @temp: buffer to write to
 * @f: formatting options
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: number of characters written to buffer
 */
int write_uns(va_list arr, char temp[], int f, int w, int p, int s)
{
	int tmp_size = 1024;
	int i = tmp_size - 2;
	unsigned long int num = va_arg(arr, unsigned long int);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		temp[i--] = '0';

	temp[tmp_size - 1] = '\0';

	while (num > 0)
	{
		temp[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, temp, f, w, p, s));
}

/**
 * write_oct - Converts an unsigned decimal number to octal
 * @arr: Va_list argument containing the number to be converted
 * @temp: Buffer to store the converted octal number
 * @f: Flags
 * @w: Minimum field width
 * @p: Precision
 * @s: Size modifier
 *
 * Return: The length of the converted number
 */
int write_oct(va_list arr, char temp[], int f, int w, int p, int s)
{
	int tmp_size = 1024;
	int i = tmp_size - 2;
	unsigned long int num = va_arg(arr, unsigned long int);
	unsigned long int init_num = num;

	(void)(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		temp[i--] = '0';

	temp[tmp_size - 1] = '\0';

	while (num > 0)
	{
		temp[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & 8 && init_num != 0)
		temp[i--] = '0';

	i++;

	return (write_unsgnd(0, i, temp, f, w, p, s));
}

/**
 * write_hex - Converts an unsigned decimal number to hexadecimal
 * @arr: Va_list argument containing the number to be converted
 * @temp: Buffer to store the converted hexadecimal number
 * @f: Flags
 * @w: Minimum field width
 * @p: Precision
 * @s: Size modifier
 *
 * Return: The length of the converted number
 */
int write_hex(va_list arr, char temp[], int f, int w, int p, int s)
{
	return (_write_hexa(arr, "0123456789abcdef", temp,
		f, 'x', w, p, s));
}

/**
 * write_hex_upper - Converts an unsigned decimal number
 *	to uppercase hexadecimal
 * @arr: Va_list argument containing the number to be converted
 * @temp: Buffer to store the converted uppercase hexadecimal number
 * @f: Flags
 * @w: Minimum field width
 * @p: Precision
 * @s: Size modifier
 *
 * Return: The length of the converted number
 */
int write_hex_upper(va_list arr, char temp[], int f, int w, int p, int s)
{
	return (_write_hexa(arr, "0123456789ABCDEF", temp,
		f, 'X', w, p, s));
}
/**
 * _write_hexa - Converts an unsigned decimal number to hexadecimal format
 * @arr: Va_list argument containing the number to be converted
 * @mapping: Mapping of hexadecimal characters
 * @temp: Buffer to store the converted hexadecimal number
 * @f: Flags
 * @fch: Flag character
 * @w: Minimum field width
 * @p: Precision
 * @s: Size modifier
 *
 * Return: The length of the converted number
 */
int _write_hexa(va_list arr, char mapping[], char temp[],
	int f, char fch, int w, int p, int s)
{
	int tmp_size = 1024;
	int i = tmp_size - 2;
	unsigned long int num = va_arg(arr, unsigned long int);
	unsigned long int init_num = num;

	(void)(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		temp[i--] = '0';

	temp[tmp_size - 1] = '\0';

	while (num > 0)
	{
		temp[i--] = mapping[num % 16];
		num /= 16;
	}

	if (f & 8 && init_num != 0)
	{
		temp[i--] = fch;
		temp[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, temp, f, w, p, s));
}

