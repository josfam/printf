# include "main.h"

/**
 * show_percent - Shows a percent sign instead of the %% that is
 *                encountered in a format string.
 * @charCount: Pointer to the number of characters printed so far.
 * Return: 0 after a successful print.
*/
int show_percent(int *charCount)
{
	_putchar('%');
	(*charCount)++;
	return (0);
}
