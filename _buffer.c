#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * create_buffer - Creates a buffer to be used for printing.
 * Return: Pointer to the created buffer.
*/
charBuffer *create_buffer()
{
	charBuffer *buffer;

	buffer = (charBuffer *)malloc(sizeof(charBuffer));

	if (buffer == NULL)
		return NULL;

	buffer->bufferPtr = buffer->chars; /* setup the pointer to the char array */
	return (buffer);
}

/**
 * append_to_buffer - Appends a character to the buffer.
 * @ch: The character to append to the buffer.
 * @buffer: Pointer to the buffer onto which to append the character.
 * @charCount: Pointer to the number of characters printed so far.
 * Description: Appends a character to the buffer.
 * Return: Nothing.
*/
void append_to_buffer(char ch, charBuffer *buffer, int *charCount)
{
	/* flush the buffer if it is almost full */
	if (buffer_is_full(buffer))
		flush_buffer(buffer, charCount);

	*(buffer->bufferPtr) = ch;
	(buffer->bufferPtr)++;
}

/**
 * flush_buffer - Writes all the buffer's contents to standard out, and
 *                effectively "resets" the buffer, such that it can accept more
 *                characters.
 * @buffer: The buffer to be flushed.
 * @charCount: Pointer to the number of characters printed so far.
 * Return: Nothing.
*/
void flush_buffer(charBuffer *buffer, int *charCount)
{
	char *start;
	int step, occupied_space;

	start = buffer->chars;
	step = 0;
	occupied_space = buffer->bufferPtr - buffer->chars;

	/* flush all buffer contents to standard out, and update character count */
	write(1, buffer, occupied_space);
	*charCount += occupied_space;

	/* fill the buffer with all '0's */
	while (step <= BUFFER_SIZE)
	{
		buffer->chars[step] = '0';
		start++;
		step++;
	}

	/* reset buffer pointers */
	buffer->bufferPtr = buffer->chars;
}

/**
 * buffer_almost_full - Returns whether the buffer is almost full.
 * @buffer: The buffer to be checked.
 * Return: Whether the buffer is considered full.
*/
int buffer_is_full(charBuffer *buffer)
{
	int leftOverSpace;

	leftOverSpace = (buffer->chars + BUFFER_SIZE) - buffer->bufferPtr;
	return (leftOverSpace <= THRESHOLD_FOR_FULL);
}

/**
 * free_buffer_memory - Frees the memory requested by a charBuffer
 * @buffer: The charBuffer whose memory to free.
 * Return: Nothing.
*/
void free_buffer_memory(charBuffer *buffer)
{
	free(buffer);
}
