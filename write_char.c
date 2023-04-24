#include "main.h"


/**
 * write_char - writes a character buffer to stdout
 * @temp: the buffer to write
 * @temp_size: a pointer to the size of the buffer
 *
 * Return: void
 */


void write_char(char temp[], int *temp_size)
{
	write(1, &temp[0], *temp_size);
	*temp_size = 0;
}
