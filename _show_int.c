#include "main.h"

/**
 * reverse - Reverses a string 'str' of length 'len'
 * @str: string to be reversed
 * @len: length of the string
 *
 */
void reverse(char *str, int len)
{
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * handleNegative - converts a negative value to positive and updates buffer
 * @value: Pointer to the integer value to be corrected
 * @isNegative: Pointer to a flag indicating if the number is negative
 * @buffer: Buffer where the negative sign will be placed if needed
 * @i: Pointer to the current index in the buffer
 */

void handleNegative(int *value, bool *isNegative, char *buffer, int *i)
{
	if (*value < 0)
	{
		*isNegative = true;
		*value = -*value;
		buffer[(*i)++] = '-';
	}
}

/**
 * convertToBase - Converts an integer value to a specified base
 * and updates buffer
 * @value: The integer to be converted
 * @buffer: Buffer where the converted value will be stored
 * @base: Numerical base for conversion
 * @i: Pointer to the current index in the buffer
 */

void convertToBase(int value, char *buffer, int base, int *i)
{
	do {
		int rem = value % base;

		buffer[*i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		(*i)++;
		value /= base;
	} while (value != 0);
}

/**
 * itoa - converts an integer value to a string rep in a given base
 *
 * @value: the integer to be converted
 * @buffer: the buffer where the converted string is stored
 * @base: numerical base for conversion (between 2 and 32)
 *
 * Return: pointer to the resulting null-terminated string
 */

char *itoa(int value, char *buffer, int base)
{
	int i = 0;
	bool isNegative = false;

	if (base < 2 || base > 32 || value == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return (buffer);
	}

	/* Handle negative ints for base 10 */
	if (base == 10)
		handleNegative(&value, &isNegative, buffer, &i);

	convertToBase(value, buffer, base, &i);

	buffer[i] = '\0';
	reverse(buffer + (isNegative ? 1 : 0), i - (isNegative ? 1 : 0));

	return (buffer);
}

/**
 * show_int - prints integer when %d or %i is encountered in a format string
 * @args: The variable arguments list
 * @charCount: Pointer to the number of characters printed so far
 * Return: 0 after a successful print
 */

int show_int(va_list args, int *charCount)
{
	int num = va_arg(args, int);
	char buffer[12]; /* buffer size to vary */
	char *str = itoa(num, buffer, 10);

	while (*str)
	{
		_putchar(*str++);
		(*charCount)++;
	}
	return (0);
}
