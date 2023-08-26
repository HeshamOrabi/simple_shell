#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stddef.h>

/* Global values */

extern char **environ;

/* structs */

/**
 * struct command - hold's all command info
 * @com: the name of the command
 * @arg: The arguments.
 * @path: pointer to fullpath command
 * @shell_name: shell name
 * @com_count: the num of comm
*/
typedef struct command
{
	char *com;
	char **arg;
	char *path;
	char *shell_name;
	int com_count;
} comd;

/**
 * struct builtin_command - Represents a built-in command
 * @name: The name of the command
 * @func: A function pointer to the command's implementation
 *
 * Description: This struct represents a built-in command,
 * It contains the name of the command and a function pointer to the
 * implementation of the command.
*/
typedef struct builtin_command
{
	char *name;
	void (*func)(comd);
} builtin_t;

/* functions */

void not_found(char *shell_name, int c, char *cmd);
void print_err_m(char *shell_name, int c);
pid_t _execve(comd c);
void free_pointers(void *ptrs, ...);
char *getcomm(comd c);
unsigned int is_delim(char c, char *delim);
char *_strtok(char *src_string, char *delim);
char *_getenv(char *name);
void bultin_env(comd c);
void bultin_exit(comd c);
int handel_pipe(char **argv);
int handel_interactive(char **argv);
int handle_builtin(comd command);
void get_command(char **buf, size_t *bufsize);
void get_buf(char **buf, size_t *bufsize);
void initialize_command(comd *c, char *buf, int count, char *argv[]);
char **gen_token(char *buf);
comd get_args(char *buf);
ssize_t _strlen(const char *str);
char *_memcpy(char *dest, const char *src);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *str);


#endif
