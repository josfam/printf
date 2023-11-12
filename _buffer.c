#include "main.h"
#include <stdlib.h>

/**
 * create_buffer - Creates a buffer to be used for printing.
 * Return: Pointer to the created buffer.
*/
charBuffer *create_buffer()
{
	charBuffer *buffer;
	buffer = (charBuffer*)malloc(sizeof(charBuffer));

	buffer->bufferPtr = buffer->chars; /* setup the pointer to the char array */
	return (buffer);
}

/**
 * flush_buffer - Writes all the buffer's contents to standard out, and
 *                effectively "resets" the buffer, such that it can accept more
 *                characters.
 * @buffer: The buffer to be flushed.
 * Return: Nothing.
*/
void flush_buffer(charBuffer *buffer)
{
	char *start;
	int step, occupied_space;

	start = buffer->chars;
	step = 0;
	occupied_space = buffer->bufferPtr - buffer->chars;

	/* output all buffer contents to standard out */
	write(1, buffer, occupied_space);

	/* fill the buffer with all '0's */
	while(step <= BUFFER_SIZE)
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
int buffer_almost_full(charBuffer *buffer)
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
