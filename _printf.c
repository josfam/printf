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
	const char *charPtr;
	va_list arguments;

	charCount = 0;
	charPtr = format;

	va_start(arguments, format);

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
			print_special(charPtr, arguments, &charCount);
			charPtr += 2; /* Skip the symbol after the % sign */
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
 * Description: Prints a character, based on the directive found after the
 *              % sign.
 * Return: 0 on success.
 */
int print_special(const char *charPtr, va_list args, int *charCount)
{
	char next_char = *(charPtr + 1); /* char after the % */

	switch (next_char)
	{
		case 'c':
			show_char(args, charCount);
			break;
		default:
			_putchar(*charPtr);
			(*charCount)++;
	}
	return (0);
}
