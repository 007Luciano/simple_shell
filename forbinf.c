#include "shell_header.h"
#define ERR "%s: %d: exit: Illegal number: %d\n"
/**
 * forbinf - executes local commands
 * @args: arguments passed
 * @argc: number of arguments passed
 * @s_cmd: number of commands executed
 * @p_name: program name
 * @st: status
 * Return: Returns 1 or 0
 */
int forbinf(int argc, char *args[], int s_cmd, char *p_name, int *st)
{
	int status = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		if (argc > 1)
		{
			status = atoi(args[1]);
			if (status < 0)
			{
				fprintf(stderr, ERR, p_name, s_cmd, status);
				return (1);
			}
			exit(status);
		}
		exit(*st);
	}

	else if (strcmp(args[0], "env") == 0)
	{
		runenv();
		return (1);
	}
	return (0);
}
