#include "main.h"

/**
 * show_char - Shows a character instead of the %c is encountered in a format
 *             string.
 * @args: The variable arguments list
 * @charCount: Pointer to the number of characters printed so far.
 * Return: 0 after a successful print.
*/
int show_char(va_list args, int *charCount)
{
	_putchar(va_arg(args, int));
	(*charCount)++;
	return (0);
}
