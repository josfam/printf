#include "main.h"

/**
 * _show_rot13 - Shows the rot13 version of the string, instead of
 *               the custom specifier, %R, that is encountered in a format
 *               string.
 * @args: The variable argument list.
 * @charCount: Pointer to the number of characters printed so far.
 * @buffer: The buffer to be used for printing.
 * Return: 0 after a successful print.
*/
int _show_rot13(va_list args, int *charCount, charBuffer *buffer)
{
	char *str;
	char ch;
	int len_str, i;

	str = va_arg(args, char *);
	len_str = _strlen(str);

	/* Add the shifted character to the buffer */
	for (i = 0; i < len_str; i++)
	{
		ch = str[i];
		append_to_buffer(_shift(ch, 13), buffer, charCount);
	}
	flush_buffer(buffer, charCount);
	return (0);
}

/**
 * _shift - Shifts the character n places forward in the alphabet.
 * @ch: The character to shift.
 * @n: The number of places to shift the char in the alphabet.
 * Description: Shifts the char n places forward in the alphabet.
 * Return: The character after shifting the char n places.
 */
int _shift(char ch, int n)
{
	int isUpperCase, isLowerCase, isAlphabetical;

	isUpperCase = (ch >= 65 && ch <= 90);
	isLowerCase = (ch >= 97 && ch <= 122);
	isAlphabetical = (isUpperCase || isLowerCase);

	/* Leave non-alphabetical characters unchanged */
	if (!isAlphabetical)
		return (ch);

	/* Shift alphabetical characters while preserving case */
	if (isLowerCase)
		return  ('a' + (ch - 'a' + n) % 26);

	return ('A' + (ch - 'A' + n) % 26);
}
