#include "main.h"

/**
 * _printf - Writes output to stdout, the standard output stream,
 *           according to a format specified in the provided character string.
 * @format: The character string that is composed of zero or more directives.
 * Description: Writes output to stdout, the standard output stream,according
 *              to a format specified in a provided character string.
 * Return: The number of characters printed, not including the null byte
 *         used to end strings.
*/
int _printf(const char *format, ...)
{
	charBuffer *buffer;
	int charCount; /* Characters printed */
	int stepForward; /* How far to move the pointer across the format string */
	const char *charPtr; /* Moves across the characters in format */
	va_list arguments;

	charCount = 0;
	charPtr = format;
	buffer = create_buffer();

	va_start(arguments, format);

	/* Print a character, while checking for directives */
	while (*charPtr != '\0')
	{
		if (*charPtr != '%')
		{
			append_to_buffer(*charPtr, buffer, &charCount);
			charPtr++;
		}
		else /* Print the character based on what's after the % */
		{
			stepForward = print_special(charPtr, arguments, &charCount, buffer);
			charPtr += stepForward; /* Advance the pointer correctly */
		}
	}
	flush_buffer(buffer, &charCount); /* Force flush the buffer */
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
 * @buffer: The buffer onto which chars will be appended.
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
			show_binary(args, charCount, buffer);
			break;
		case 'c':
			show_char(args, charCount, buffer);
			break;
		case 's':
			show_string(args, charCount);
			break;
		case '%':
			show_percent(charCount, buffer);
			break;
		case 'd':
		case 'i':
			show_int(args, charCount);
			break;
		default:
			_putchar(*charPtr);
			(*charCount)++;
			return (1); /* Do not skip the char after the % sign */
	}
	return (2); /* Skip the char after the % sign */
}
