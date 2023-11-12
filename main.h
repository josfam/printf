#ifndef _PRINTF_HEADER
#define _PRINTF_HEADER
#include <stdarg.h>
#include <stddef.h>

/* Writes a character to standard output. */
void _putchar(char ch);

/* Produces output according to a format */
int _printf(const char *format, ...);

/* Prints a character, based on the directive found after the % sign. */
int print_special(const char *charPtr, va_list arguments, int *charCount);

/* Shows a character instead of the %c is encountered in a format string. */
int show_char(va_list args, int *charCount);

/* Shows a percent sign instead of the %% encountered in a format string. */
int show_percent(int *charCount);

/* Shows a string instead of %s when encountered in a format string. */
int show_string(va_list args, int *charCount);

/* Shows the binary representation of a number *custom specifier, %b, */
/* that is encountered in a format string. */
int show_binary(va_list args, int *charCount);

#endif
