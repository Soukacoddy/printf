#include "main.h"

/**
 * write_str - Writes a string to stdout
 * @arr: A va_list of arguments
 * @temp: A buffer to write the formatted output
 * @f: Flags that modify the behavior of the conversion
 * @w: Minimum field width of the conversion
 * @p: Precision of the conversion
 * @s: Length modifier specifying the size of the argument
 *
 * Return: The number of characters written to stdout
 */

int write_str(va_list arr, char temp[], int f, int w, int p, int s)
{
	int length = 0, i;
	char *str = va_arg(arr, char *);

	(void) temp;
	(void) f;
	(void) s;

	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
		str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (p >= 0 && p < length)
		length = p;

	if (w > length)
	{
		if (f & 1)
		{
			write(1, &str[0], length);
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (w);
		}
	}

	return (write(1, str, length));
}



/**
 * write_per - Writes the '%' character to stdout
 * @arr: A va_list of arguments
 * @temp: A buffer to write the formatted output
 * @f: Flags that modify the behavior of the conversion
 * @w: Minimum field width of the conversion
 * @p: Precision of the conversion
 * @s: Length modifier specifying the size of the argument
 *
 * Return: The number of characters written to stdout
 */

int write_per(va_list arr, char temp[], int f, int w, int p, int s)
{
	(void) arr;
	(void) temp;
	(void) f;
	(void) w;
	(void) p;
	(void) s;

	return (write(1, "%%", 1));
}


/**
 * write_char_function - writes a character to stdout
 * @arr: argument list that contains the character to be printed
 * @temp: buffer to hold the formatted output
 * @f: flags to modify output (not used here)
 * @w: minimum width of output (not used here)
 * @p: precision of output (not used here)
 * @s: length modifier for output (not used here)
 *
 * Return: number of characters printed
 */

int write_char_function(va_list arr, char temp[], int f, int w, int p, int s)
{
	char c = va_arg(arr, int);

	return (_write_char(c, temp, f, w, p, s));
}


/**
 * write_int - Convert integer to string and write to buffer
 *
 * @arr: argument list containing integer to convert
 * @temp: buffer to write converted integer to
 * @f: format flags
 * @w: minimum field width
 * @p: precision
 * @s: size modifier
 *
 * Return: Number of characters written to buffer
 */
int write_int(va_list arr, char temp[], int f, int w, int p, int s)
{
	int temp_size = 1024;
	int i = temp_size - 2;
	int is_negative = 0;
	long int n = va_arg(arr, long int);
	unsigned long int num;

	n = convert_size_number(n, s);

	if (n == 0)
		temp[i--] = '0';

	temp[temp_size - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		temp[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, temp, f, w, p, s));
}


/**
 * write_b - writes an unsigned int to stdout in binary
 * @arr: va_list of arguments
 * @temp: buffer to write to
 * @f: formatting flags
 * @w: minimum width of the printed integer
 * @p: precision of the printed integer
 * @s: size of the integer (e.g. short, long, long long)
 *
 * Return: number of characters written
 */
int write_b(va_list arr, char temp[], int f, int w, int p, int s)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	(void) temp;
	(void) f;
	(void) w;
	(void) p;
	(void) s;

	n = va_arg(arr, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
