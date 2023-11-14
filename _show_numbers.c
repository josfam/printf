#include "main.h"

/**
 * show_number - Prints a number in a specified base when
 * %u, %o, %x or %X is encountered in a format string
 * @args: The variable arguments list
 * @charCount: Pointer to the number of characters printed so far
 * @base: The base to print the number
 * (10 for unsigned, 8 for octal, 16 or -16 for hexadecimal)
 * Return: 0 Success
 */

int show_number(va_list args, int *charCount, int base)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];
	char *str = itoa(num, buffer, base);

	while (*str)
	{
		_putchar(*str++);
		(*charCount)++;
	}
	return (0);
}
