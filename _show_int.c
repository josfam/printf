#include main.h

/**
 * show_int - Shows an integer instead of %d in a format string
 * @args: The variable arguments list
 * @charCount: Pointer to the number of characters printed
 * Return: 0
 */

int show_int (va_list args, int *charCount)
{
	int num;
	char *str;
	char buffer[12]; /*okay for 32bits,to increase for 64 bits */

	num = va_arg(args, int);
	str = itoa(num, buffer, 10); /* itoa to convert int to string */

	while (*str)
	{
		_putchar(*str++);
		(*charCount)++;
	}
	return (0);
}
