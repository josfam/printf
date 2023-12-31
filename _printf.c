#include "main.h"

/**
 * _printf - Writes output to stdout, the standard output stream,
 *           according to a format specified in the provided character string.
 * @format: The character string that is composed of zero or more directives.
 * Description: Writes output to stdout, the standard output stream,
 *              according to a format specified in a provided character string.
 * Return: The number of characters printed, not including the null byte
 *         used to end strings.
*/
int _printf(const char *format, ...)
{
	int charCount; /* Characters printed */
	int stepForward; /* How far to move the pointer across the format string */
	const char *charPtr; /* Moves across the characters in format */
	va_list arguments;
	charBuffer *buffer;

	charCount = 0;
	charPtr = format;
	buffer = create_buffer();

	va_start(arguments, format);

	if (!buffer || !format)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0]  == '%' && format[1] == '\0')
		return (-1);

	/* Print a character, while checking for directives */
	while (*charPtr != '\0')
	{
		if (*charPtr != '%')
		{
			_putchar(*charPtr);
			charCount++;
			charPtr++;
		}
		else /* Print the character based on what's after the % */
		{
			stepForward = print_special(charPtr, arguments, &charCount, buffer);
			charPtr += stepForward; /* Advance the pointer correctly */
		}
	}
	va_end(arguments);
	free_buffer_memory(buffer);

	return (charCount);
}

/**
 * print_special - Prints a character, based on the directive found after the
 *                 % sign.
 * @charPtr: Pointer to the current position in the format string being
 *           investigated.
 * @args: The variable arguments list.
 * @charCount: Pointer to the number of characters printed so far.
 * @buffer: Pointer to a buffer onto which characters are appended.
 * Description: Prints a character, based on the directive found after the
 *              % sign.
 * Return: The number of steps that the pointer that is moving across
 *         the format string should advance forward.
 */
int print_special(const char *charPtr, va_list args, int *charCount,
					charBuffer *buffer)
{
	char next_char = *(charPtr + 1); /* char after the % */

	if (next_char == 'b')
		show_binary(args, charCount, buffer);
	else if (next_char == 'c')
		show_char(args, charCount);
	else if (next_char == 's')
		show_string(args, charCount);
	else if (next_char == '%')
		show_percent(charCount);
	else if (next_char == 'd')
		show_int(args, charCount);
	else if (next_char == 'i')
		show_int(args, charCount);
	else if (next_char == 'u')
		show_number(args, charCount, 10);
	else if (next_char == 'o')
		show_number(args, charCount, 8);
	else if (next_char == 'R')
		_show_rot13(args, charCount, buffer);
	else if (next_char == 'x')
		show_number(args, charCount, 16);
	else if (next_char == 'X')
		show_number(args, charCount, -16);
	else
	{
		_putchar(*charPtr);
		(*charCount)++;
		return (1); /* Do not skip the char after the % sign */
	}

	return (2); /* Skip the char after the % sign */
}
