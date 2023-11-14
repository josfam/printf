# include "main.h"
#include <limits.h>

/**
 * show_binary - Shows the binary representation of a number instead of the
 *               custom specifier, %b, that is encountered in a format string.
 * @args: The variable argument list.
 * @charCount: Pointer to the number of characters printed so far.
 * @buffer: The buffer to be used for printing.
 * Return: 0 after a successful print.
*/
int show_binary(va_list args, int *charCount, charBuffer *buffer)
{
	int i, j;
	unsigned int num;
	int binary_nums[sizeof(int) * 8];

	i = 0;
	num = va_arg(args, int);

	/* handle 0, and a number greater than the theoretical maximum integer */
	if (num == 0 || num > UINT_MAX)
	{
		append_to_buffer('0', buffer, charCount);
		return (0);
	}

	while (num > 0)
	{
		binary_nums[i] = num % 2;
		num /= 2;
		i++;
	}

	/* print the binary numbers from right to left */
	for (j = i - 1; j >= 0; j--)
	{
		append_to_buffer('0' + binary_nums[j], buffer, charCount);
	}

	flush_buffer(buffer, charCount);

	return (0);
}
