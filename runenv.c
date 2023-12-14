#include "shell_header.h"
/**
 * runenv - prints environment variables
 * Return: Returns void
 */
void runenv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
