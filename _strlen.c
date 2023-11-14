#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to return.
 * Description: Returns the length of a string.
 * Return: The length of the string, s.
 */
int _strlen(const char *s)
{
	int len;
	int counter;

	counter = 0;
	len = 0;

	while (*(s + counter) != '\0')
	{
		len++;
		counter++;
	}

	return (len);
}
