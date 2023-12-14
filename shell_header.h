#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdint.h>
#define ARGS_LIMIT 1024
#define BUF_SIZE 200
#define ERR "%s: %d: exit: Illegal number: %d\n"

void custom_print(const char *strng);
ssize_t cmd_read(char **lineptr, size_t *n, FILE *stream);
void exec_cmd(char *command, int scounter, char *bashpg);
int forbinf(int argc, char *args[], int s_cmd, char *p_name, int *st);
void shell_error(int scounter, char *args[], char *program_name);
extern char **environ;
ssize_t charead(char **lineptr, size_t *n, char *buffer,
		size_t *buf_position, size_t *buff_size, FILE *stream);
void runenv(void);

#endif
