
# C - printf

This repository contains C programs that implement a data structure for dogs. The programs were completed as part of the Holberton School curriculum.
 <div align="center"  style='color:#008F11;'>
<img   src="https://i.giphy.com/media/CcwLAV11cALh3OuEJ5/giphy.webp" alt="c" width="60%" height="auto"/> 
 
 </div>


## Authors

- [@hamza-essalhi](https://www.github.com/hamza-essalhi)
- [@Soukacoddy](https://github.com/Soukacoddy)



## 🚀 About _Printf Function


<h5>The _printf function is a variadic function that allows you to print formatted output to the console in a similar way to the standard library printf function. The _printf function is declared as follows:</h5>

```c
int _printf(const char *format, ...);
```

<h5>List of format specifiers supported by _printf:</h5>
<ul>
  <li><strong>%c:</strong> Prints a single character.</li>
  <li><strong>%s:</strong> Prints a string of characters.</li>
  <li><strong>%d or %i:</strong> Prints a signed integer.</li>
  <li><strong>%u:</strong> Prints an unsigned integer.</li>
  <li><strong>%o:</strong> Prints an unsigned octal number.</li>
  <li><strong>%x or %X:</strong> Prints an unsigned hexadecimal number in lowercase or uppercase, respectively.</li>
  <li><strong>%%:</strong> Prints a literal % character.</li>
</ul>
<h3>get_flags:</h3>

```c
int get_flags(const char *format, int *i)
```
<ul>
  <li>A function that extracts any flags in the format string. It checks each character after a % symbol and returns an integer representing the flags set. The possible flags are '-', '+', '0', '#', and ' '.</li>
</ul>
<h3>get_width:</h3>
<ul>
  <li>A function that extracts the field width from the format string. It checks each character after a % symbol and returns an integer representing the field width. If the character is '*', it reads the width from the argument list.</li>
</ul>
<h3>get_precision:</h3>
<ul>
  <li>A function that extracts the precision value from the format string. It checks each character after a % symbol and returns an integer representing the precision value. If the character is '*', it reads the precision value from the argument list.</li>
</ul>
<h3>get_size:</h3>
<ul>
  <li>A function that extracts the length modifier from the format string. It checks each character after a % symbol and returns an integer representing the length modifier. The possible length modifiers are 'l' and 'h'.</li>
</ul>
<h3>handle_print function:</h3>
<p>This function takes a format specifier as input and chooses the appropriate function to handle the specifier. It also takes in several other arguments that are used to modify the formatting.</p>
<p>The function first defines an array of structs called function_arr, which contains a list of all the possible format specifiers and their corresponding functions to handle them. The function then iterates through the array and checks if the current specifier matches any of the ones in the array. If a match is found, the corresponding function is called and passed the necessary arguments. If no match is found, an error is returned.</p>
<p>If the function encounters a percent sign (%) that is not followed by a valid format specifier, it treats it as a literal percent sign and prints it to the output. If the previous character was a space, it also prints a space before the percent sign. If the width modifier is present, the function backtracks and finds the start of the format specifier to determine the appropriate width.</p>
<p>The function returns the number of characters written to the output, or -1 if an error occurs.</p>


## How to use  _printf()
<h5>This is a C function called _printf, which is a custom implementation of the printf function. The function takes a format string containing format specifiers, and a variable number of arguments, and returns the number of characters printed.</h5>

<p>To use this function, you would first need to include the "main.h" header file that contains the function prototype. You can then call the function like any other C function, passing in the format string and any additional arguments.</p>

<p>The function works by iterating through the characters in the format string, and either writing them to a temporary buffer or processing format specifiers. The get_flags, get_width, get_precision, and get_size helper functions are used to extract information from the format specifiers. The handle_print function is responsible for actually printing the formatted output to the temporary buffer.</p>

<p>Once the entire format string has been processed, the function writes any remaining characters in the temporary buffer to standard output, and returns the total number of characters printed. If there was an error during processing, the function returns -1.</p>
<ul>
  <li>
    <h4>write_str():</h4>
    <p>This function writes a string to standard output. It takes in a <code>va_list</code> of arguments, a buffer for formatted output, format flags, minimum field width, precision, and length modifier as parameters. It then extracts a <code>char</code> pointer from the <code>va_list</code> of arguments and calculates its length. If the precision is greater than or equal to zero and less than the length of the string, the function uses the precision as the length of the string. If the minimum field width is greater than the length of the string, it pads the output with spaces to the left or right depending on the <code>f</code> flag. It then returns the number of characters written to standard output.</p>
  </li>
  <li>
    <h4>write_per():</h4>
    <p>This function writes a single percent character to standard output. It takes in a <code>va_list</code> of arguments, a buffer for formatted output, format flags, minimum field width, precision, and length modifier as parameters. It does not use any of these parameters and simply returns the number of characters written to standard output.</p>
  </li>
  <li>
    <h4>write_char_function():</h4>
    <p>This function writes a single character to standard output. It takes in a <code>va_list</code> of arguments, a buffer for formatted output, format flags, minimum field width, precision, and length modifier as parameters. It extracts a char from the <code>va_list</code> of arguments and passes it to the <code>_write_char()</code> function to write it to standard output. It then returns the number of characters written to standard output.</p>
  </li>
</ul>
<h3>Function: write_int()</h3>
<ul>
  <li>Converts an integer to a string and writes it to standard output.</li>
  <li>Takes in a <code>va_list</code> of arguments, a buffer for formatted output, format flags, minimum field width, precision, and length modifier as parameters.</li>
  <li>Extracts a long int from the <code>va_list</code> of arguments and converts it to an unsigned long int.</li>
  <li>Converts the unsigned long int to a string and writes it to the buffer.</li>
  <li>Takes into account the format flags, minimum field width, precision, and length modifier when writing the integer to the buffer.</li>
  <li>Returns the number of characters written to standard output.</li>
</ul>

<h3>Function: write_b()</h3>
<ul>
  <li>Writes an unsigned integer to standard output in binary format.</li>
  <li>Takes in a <code>va_list</code> of arguments, a buffer for formatted output, format flags, minimum field width, precision, and length modifier as parameters.</li>
  <li>Extracts an unsigned int from the <code>va_list</code> of arguments and converts it to binary format.</li>
  <li>Writes the binary representation to standard output, taking into account the format flags, minimum field width, precision, and length modifier.</li>
  <li>Returns the number of characters written to standard output.</li>
</ul>

<h3>Function: is_digit()</h3>
<ul>
  <li>Takes a character as input and checks whether it is a digit or not.</li>
  <li>Returns 1 if the character is a digit, and 0 otherwise.</li>
</ul>

<h3>Function: convert_size_unsgnd()</h3>
<ul>
  <li>Takes an unsigned long integer and a size as input, and converts the integer to a smaller size (either 2 or 4 bytes).</li>
  <li>Returns the converted integer.</li>
</ul>

<h3>Function: convert_size_number()</h3>
<ul>
  <li>Takes a long integer and a size as input, and converts the integer to a smaller size (either 1 or 2 bytes).</li>
  <li>Returns the converted integer.</li>
</ul>

<h3>Function: is_printable()</h3>
<ul>
  <li>Takes a character as input and checks whether it is a printable character or not.</li>
  <li>Returns 1 if the character is printable, and 0 otherwise.</li>
</ul>

<h3>Function: append_hexa_code()</h3>
<ul>
  <li>Takes an ASCII code, a string, and an index as input, and appends the hexa representation of the ASCII code to the string at the given index.</li>
  <li>Returns the number of characters appended to the string.</li>
</ul>

<h4>Function: _write_char()</h4>
<ul>
  <li>Writes a single character to stdout using a character buffer.</li>
  <li>Takes a character, a character buffer, formatting flags, field width, precision, and size of the data type as input parameters.</li>
  <li>Returns the number of characters written to stdout.</li>
</ul>

<h4>Function: write_num()</h4>
<ul>
  <li>Writes a number to a buffer with certain formatting options.</li>
  <li>Takes the starting index of the number in the buffer, the buffer itself, formatting flags, field width, precision specifier, length of the number, padding character, and an extra character as input parameters.</li>
  <li>Returns the number of characters printed.</li>
</ul>

<h4>Function: write_number()</h4>
<ul>
  <li>Description: prints a signed integer to stdout with certain formatting options.</li>
  <li>Parameters: flag indicating whether the number is negative or not, starting index of the buffer, buffer, formatting flags, field width, precision specifier, and size specifier.</li>
  <li>Return: number of characters printed.</li>
</ul>

<h4>Function: write_unsgnd()</h4>
<ul>
  <li>Description: writes an unsigned integer to a buffer with certain formatting options.</li>
  <li>Parameters: flag indicating whether the number is negative or not, starting index of the buffer, buffer, formatting flags, field width, precision specifier, and size specifier.</li>
  <li>Return: number of characters printed.</li>
</ul>




## Below is a codeblock with c  - with syntax highlighting of _printf()
```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	return (0);
}
```

## Output
```console
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
```

## Badges



[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![AGPL License](https://img.shields.io/badge/license-AGPL-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)

