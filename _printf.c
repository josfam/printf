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

	charCount = 0;
	charPtr = format;

	va_start(arguments, format);

	if (!format)
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
			stepForward = print_special(charPtr, arguments, &charCount);
			charPtr += stepForward; /* Advance the pointer correctly */
		}
	}
	va_end(arguments);

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

	switch (next_char)
	{
		case 'b':
			show_binary(args, charCount);
			break;
		case 'c':
			show_char(args, charCount);
			break;
		case 's':
			show_string(args, charCount);
			break;
		case '%':
			show_percent(charCount);
			break;
		case 'd':
			show_int(args, charCount);
			break;
		case 'i':
			show_int(args, charCount);
			break;
		case 'u':
			show_number(args, charCount, 10);
			break;
		case 'o':
			show_number(args, charCount, 8);
			break;
		case 'x':
			show_number(args, charCount, 16);
			break;
		case 'X':
			show_number(args, charCount, -16);
			break;
		default:
			_putchar(*charPtr);
			(*charCount)++;
			return (1); /* Do not skip the char after the % sign */
	}
	return (2); /* Skip the char after the % sign */
}
