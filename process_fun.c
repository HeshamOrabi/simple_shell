#include "main.h"

/**
 * print_prompt - print a prompt if in interactive mode.
 */
void print_prompt(void)
{
	char prompt[] = "$ ";
	int len = _strlen(prompt);

	/* Printing the prompt */
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(1, prompt, len);
}

/**
 * get_input - gets a line and check if it is the end.
 * @line: a pointer to the cmd line string
 * @buffsize: a pointer to the buffer size created for the line
 * Return: number of chars of the cmd line
 */

ssize_t get_input(char **line, size_t *buffsize)
{
	ssize_t strl;
	strl = getline(line, buffsize, stdin);
	if (strl == -1)
	{	
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			write(STDIN_FILENO, "\n", 1);
		free(*line);
		exit(0);
	}
	return (strl);
}

/**
 * _execv - executes command
 * @command: the command that will execute
 * @argv: the array of string
 * Return: returns 0 .
 */
int _execv(const char *command, char **argv, char *av, char **envp)
{
	pid_t id;

	if (command == NULL)
	{
		perror(av);
		return (-1);
	}
	else
		id = fork();
	if (id == 0)
	{
		if (execve(command, argv, envp) == -1)
		{
			perror(av);
			exit(-1);
		}
	}
	else
		wait(&id);
	return (0);
}
