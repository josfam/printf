#include "main.h"

/**
 * show_char - Shows a character instead of the %c is encountered in a format
 *             string.
 * @args: The variable arguments list
 * @charCount: Pointer to the number of characters printed so far.
 * Return: 0 after a successful print.
*/
int show_char(va_list args, int *charCount, charBuffer *buffer)
{
	append_to_buffer(va_arg(args, int), buffer, charCount);
	return (0);
}
