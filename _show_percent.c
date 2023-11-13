# include "main.h"

/**
 * show_percent - Shows a percent sign instead of the %% that is
 *                encountered in a format string.
 * @charCount: Pointer to the number of characters printed so far.
 * @buffer: The buffer onto which characters will be appended.
 * Return: 0 after a successful print.
*/
int show_percent(int *charCount, charBuffer *buffer)
{
	append_to_buffer('%', buffer, charCount);
	return (0);
}
