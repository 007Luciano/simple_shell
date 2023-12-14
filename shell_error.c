#include "shell_header.h"
/**
 * shell_error- prints errors
 * @scounter: number of times a command is executed
 * @args: contains program name
 * @program_name: name of dhell program
 * Return: void
 */
void shell_error(int scounter, char *args[], char *program_name)
{
	printf("%s %d: %s: not found\n", program_name, scounter, args[0]);
}
