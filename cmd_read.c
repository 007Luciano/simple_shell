#include "shell_header.h"
/**
 * cmd_read - getline function that retrieve input
 * @lineptr: pointer to line command from standard input
 * @n: size of the buffer line
 * @stream: standard stream input to be read
 * Return: Returns the number of lines read
 */
ssize_t cmd_read(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUF_SIZE];
	static size_t buf_position;
	static size_t buff_size;
	ssize_t bytes_readn = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = 200;
		*lineptr = (char *)malloc(*n);

		if (*lineptr == NULL)
			return (-1);
	}
	bytes_readn = charead(lineptr, n, buffer, &buf_position, &buff_size, stream);
	return (bytes_readn);
}
