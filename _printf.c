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

	charCount = 0;
	charPtr = format;

	/* Naively print every character that is encountered */
	while (*charPtr != '\0')
	{
		_putchar(*charPtr);
		charCount++;
		charPtr++;
	}

	return (charCount);
}
