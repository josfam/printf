#include "main.h"

/**
 * Reverses a string 'str' of length 'len'
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
 * itoa - converts an integer value to a string
 *
 * @value: the integer to be converted
 * @buffer: the buffer where the converted string is stored
 * base: numerical base
 *
 * Return: pointer to the resulting null-terminated string
 */

char *itoa(int value, char *buffer, int base)
{
	int i = 0;
	bool isNegative = false;

	if (base < 2 || base >32)
	{
		*buffer = '\0';
		return buffer;
	}
	
	if (value == 0)

	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return buffer;
	}

	if (value < 0 && base == 10)
	{
		isNegative = true;
		value = -value;
	}

	while (value != 0)
	{
		int rem = value % base;
		buffer[i++] = (rem > 9) ? (rem - 10)+ 'a' : rem + '0';
		value = value/base;
	}
	
	if (isNegative)
	{
		buffer[i++] = '-';
	}

	buffer[i] = '\0';

	reverse(buffer, i);

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
	char buffer[12];
	char *str = itoa(num, buffer, 10);

	while (*str)
	{
		_putchar(*str++);
		(*charCount)++;
	}
	return (0);
}
