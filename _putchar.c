#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to standard output.
 * @ch: The character to write to standard out.
 * Description: Writes a character to standard output.
 * Return: Nothing
 */
void _putchar(char ch)
{
	write(1, &ch, sizeof(char));
}
