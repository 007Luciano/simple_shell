#include "shell_header.h"
/**
 * custom_print - prints strings to output
 * @strng: string to be print in stdo
 * Return: Returns void
 */
void custom_print(const char *strng)
{
	size_t string_length = 0;
	const char *strng_pointer = strng;
	ssize_t nbytes = 0;

	while (*strng_pointer != '\0')
	{
		string_length++;
		strng_pointer++;
	}

	nbytes = write(STDOUT_FILENO, strng, string_length);

	if (nbytes == -1)
	{
		exit(EXIT_FAILURE);
	}
}
