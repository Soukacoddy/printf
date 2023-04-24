#include "main.h"


/**
 * _write_pointer - Write a memory address
 * @temp: Arrays of chars
 * @con: Index at which the number starts in the buffer
 * @len: Length of number
 * @w: Width specifier
 * @f: Flags specifier
 * @txt: Char representing the padding
 * @_char: Char representing extra char
 * @st_txt: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int _write_pointer(char temp[], int con, int len,
	int w, int f, char txt, char _char, int st_txt)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			temp[i] = txt;
		temp[i] = '\0';
		if (f & 1 && txt == ' ')
		{
			temp[--con] = 'x';
			temp[--con] = '0';
			if (_char)
				temp[--con] = _char;
			return (write(1, &temp[con], len) + write(1, &temp[3], i - 3));
		}
		else if (!(f & 1) && txt == ' ')
		{
			temp[--con] = 'x';
			temp[--con] = '0';
			if (_char)
				temp[--con] = _char;
			return (write(1, &temp[3], i - 3) + write(1, &temp[con], len));
		}
		else if (!(f & 1) && txt == '0')
		{
			if (_char)
				temp[--st_txt] = _char;
			temp[1] = '0';
			temp[2] = 'x';
			return (write(1, &temp[st_txt], i - st_txt) +
				write(1, &temp[con], len - (1 - st_txt) - 2));
		}
	}
	temp[--con] = 'x';
	temp[--con] = '0';
	if (_char)
		temp[--con] = _char;
	return (write(1, &temp[con], len));
}
