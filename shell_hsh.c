#include "shell_header.h"
/**
 * main - Entry Point
 * @argc: number of arguments
 * @argv: list of arguments being passed
 * Return: Returns 0 for success
 */
int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t buf_size = 0;
	ssize_t nbytes_read = 0;
	int flag_pipe = 0;
	static int scounter = 1;

	(void) argc;
	(void) argv;

	--scounter;
	if (!isatty(STDIN_FILENO))
	{
		flag_pipe = 1;
	}

	if (!flag_pipe)
	{
		custom_print("$ ");
	}

	while ((nbytes_read = cmd_read(&command, &buf_size, stdin)) != EOF)
	{
		if (nbytes_read == 1)
		{
			if (!flag_pipe)
				scounter++;
		}
		else
		{
			if (command[nbytes_read - 1] == '\n')
				command[nbytes_read - 1] = '\0';

			exec_cmd(command, scounter, argv[0]);
			scounter++;
		}
		if (!flag_pipe)
			custom_print("$ ");
	}
	if (nbytes_read <= 0 && !flag_pipe)
		putchar('\n');
	free(command);
	return (0);
}
