#ifndef _PRINTF_HEADER
#define _PRINTF_HEADER
#include <stdarg.h>

/* Writes a character to standard output. */
void _putchar(char ch);

/* Produces output according to a format */
int _printf(const char *format, ...);

/* Prints a character, based on the directive found after the % sign. */
int print_special(const char *charPtr, va_list arguments, int *charCount);

#endif
