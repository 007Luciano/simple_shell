#include "shell_header.h"
/**
 * exec_cmd - function to execute user command
 * @command: the command to be executed
 * @scounter: number of commands executed
 * @bashpg: name of the program used in bin bash
 * Return: Returns nothing
 */
void exec_cmd(char *command, int scounter, char *bashpg)
{
	char *args[ARGS_LIMIT];
	int argc = 0;
	static int exit_status;
	pid_t pid;

	char *token = strtok(command, " \t\n");

	scounter++;

	while (token != NULL && argc < ARGS_LIMIT - 1)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	args[argc] = NULL;
	if (args[0] == NULL)
		return;
	if (forbinf(argc, args, scounter, bashpg, &exit_status))
		return;
	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		shell_error(scounter, args, bashpg);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &exit_status, 0);
}
