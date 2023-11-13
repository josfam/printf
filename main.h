#ifndef _PRINTF_HEADER
#define _PRINTF_HEADER
#include <stdarg.h>
#include <stddef.h>

#define BUFFER_SIZE 1024
/* empty space left before buffer is 'full' and has to be flushed */
#define THRESHOLD_FOR_FULL 1

/* The buffer struct to be used when printing to standard out. */
typedef struct charBuffer
{
	char chars[BUFFER_SIZE];
	char *bufferPtr;
} charBuffer;

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

/* Creates a buffer to be used for printing. */
charBuffer *create_buffer();

/* Appends a character to the buffer. */
void append_to_buffer(char ch, charBuffer *buffer);

/* flush_buffer - Writes all the buffer's contents to standard out. */
void flush_buffer(charBuffer *buffer);

/* Returns whether the buffer is almost full. */
int buffer_almost_full(charBuffer *buffer);

/* Frees the memory requested by a charBuffer. */
void free_buffer_memory(charBuffer *buffer);

#endif
