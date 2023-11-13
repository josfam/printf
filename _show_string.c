# include "main.h"

/**
 * show_string - Shows a string instead of %s in a format string
 * @args: The variable argument list
 * @charCount: Pointer to the number of characters printed so far
 * Return: 0 after a successful print
 */

int show_string(va_list args, int *charCount)
{
	const char *str = va_arg(args, const char *);

	if (!str)
		str = "(null)";

	while (*str)
	{
		_putchar(*str++);
		(*charCount)++;
	}
	return (0);

}
