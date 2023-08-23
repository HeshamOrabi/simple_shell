#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

int _strlen(const char *str);

/**
 * struct full_command - a struct that holds the command
 * and arguments passed.
 * @cmd: the command name.
 * @args: the arguments passed to the program.
 * @get_line: a pointer to the full command
 */
typedef struct full_command
{
	char *cmd;
	char **args;
	char *buffer;
} f_cmd;

extern char **environ;

void print_prompt(void);
ssize_t get_input(char **line, size_t *buffsize);
char *_strcpy(char *dest, char *src);
char **get_tokens(char *buf, char *av);
f_cmd _get_argv(char *buf, char *av);
int _execv(const char *command, char **argv, char *av, char**envp);
void _free(void *p1, ...);
int check_empty_str(char *str);
char *get_envpath();
char *_strdup(char *str);
char *_which(char *cmd);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);



#endif
