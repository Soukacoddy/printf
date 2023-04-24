#ifndef MAIN_H
#define MAIN_H

/* Main library */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 *  struct fdatat - struct controller
 *  @char_f: format
 *  @function: function to handel
 */

struct fdatat
{
	char char_f;
	int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fdatat fdatat_f - Struct op
 *
 * @fdatat: The format.
 * @fdatat_f: The function associated.
 */

typedef struct fdatat fdatat_f;

/* auther functions */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
long int convert_size_number(long int num, int size);
int is_digit(char);
int append_hexa_code(char ascii_code, char temp[], int i);
int is_printable(char c);

/* Functions */

int write_rot13(va_list arr, char temp[], int f,
	int w, int prc, int s);
int write_rev(va_list arr, char temp[], int f,
	int w, int prc, int s);
int write_pointer(va_list arr, char temp[], int f,
	int w, int prc, int s);
int write_unprintable(va_list arr, char temp[],
	int f, int w, int prc, int s);
void write_char(char temp[], int *temp_size);
int _printf(const char *format, ...);
int write_b(va_list arr, char temp[], int f, int w,
	int p, int s);
int write_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_char_function(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _write_char(char c, char arr[],
	int f, int w, int p, int s);
int write_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_per(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c);
int handle_print(const char *specifier_value, int *index,
	va_list arr, char temp[], int flgs, int wth, int prc, int s);

int _write_hexa(va_list arr, char mapping[], char temp[],
	int f, char fch, int w, int p, int s);
int write_hex(va_list arr, char temp[], int f,
	int w, int p, int s);

int write_oct(va_list arr, char temp[], int f,
	int w, int p, int s);
int write_hex_upper(va_list arr, char temp[], int f,
	int w, int p, int s);
int _write_hex(va_list arr, char mapping[], char temp[],
	int f, char fch, int w, int p, int s);
int write_uns(va_list arr, char temp[], int f,
	int w, int p, int s);
long int convert_size_unsgnd(unsigned long int num, int size);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
	int width, int precision, int size);
int _write_pointer(char temp[], int con, int len,
	int w, int f, char txt, char _char, int st_txt);
/*handlers*/

int get_width(const char *format, int *i, va_list arr);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list arr);
int get_size(const char *format, int *i);




#endif /* MAIN_H */


