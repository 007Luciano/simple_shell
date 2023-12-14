#include "shell_header.h"
/**
 * charead - custom getline function
 * @lineptr: pointer to line command from standard input
 * @buff_size: current size of the buffer
 * @n: size of the buffer line
 * @stream: standard stream input to be read
 * @buf_position: current buffer possion
 * @buffer: preloaded input of stream
 * Return: Returns the number of lines
 */
ssize_t charead(char **lineptr, size_t *n, char *buffer,
		size_t *buf_position, size_t *buff_size, FILE *stream)
{
	size_t i = 0;
	int j;
	char *cp_ptr = NULL;

	while (1)
	{
		if (*buf_position >= *buff_size)
		{
			*buf_position = 0;
			*buff_size = read(fileno(stream), buffer, BUF_SIZE);
			if (*buff_size == 0)
				break;
			else if (*buff_size == SIZE_MAX)
				return (-1);
		}
		j = buffer[(*buf_position)++];
		if (i >= *n - 1)
		{
			*n *= 2;
			cp_ptr = (char *) realloc(*lineptr, *n);
			if (cp_ptr == NULL)
				return (-1);
			*lineptr = cp_ptr;
		}
		(*lineptr)[i++] = j;

		if (j == '\n')
			break;
	}

	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
