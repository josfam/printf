# include "main.h"
#include <limits.h>

/**
 * show_binary - Shows the binary representation of a number instead of the
 *               custom specifier, %b, that is encountered in a format string.
 * @args: The variable argument list.
 * @charCount: Pointer to the number of characters printed so far.
 * Return: 0 after a successful print.
*/
int show_binary(va_list args, int *charCount)
{
	int i, j, num;
	int binary_nums[sizeof(int) * 8]; /**/

	i = 0;
	num = va_arg(args, int);

	/* handle 0, and a number greater than the theoretical maximum integer */
	if (num == 0 || num > UINT_MAX)
	{
		_putchar('0' + binary_nums[j]);
		(*charCount)++;
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
		_putchar('0' + binary_nums[j]);
		(*charCount)++;
	}

	return (0);
}
