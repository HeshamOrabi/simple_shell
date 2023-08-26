#include "main.h"

/**
 * handel_pipe - handele noninteractive mode
 * @argv: array of string
 * Return: 0 seucces
*/
int handel_pipe(char **argv)
{
	comd command;
	char *buf = NULL;
	size_t bufsize;
	int count = 0;
	pid_t id;

	while (1)
	{
		get_buf(&buf, &bufsize);
		count++;
		command = get_args(buf);
		initialize_command(&command, buf, count, argv);
		if (command.com != NULL)
		{
			if (!handle_builtin(command))
			{
				command.com = getcomm(command);
				if (command.com != NULL)
					id = _execve(command);
				if (command.com == NULL && (!isatty(STDIN_FILENO)))
					return (127);
				free(command.com);
			}
		}
		free_pointers(command.arg, buf, NULL);
		buf = NULL;
	}
	return (id);
}
/**
 * handel_interactive - handele interactive mode
 * @argv: array of string
 * Return: 0 seucces
*/
int handel_interactive(char **argv)
{
	comd command;
	char *buf = NULL;
	size_t bufsize;
	int count = 0;
	pid_t id;

	get_command(&buf, &bufsize);
	count++;
	command = get_args(buf);
	initialize_command(&command, buf, count, argv);
	if (command.com != NULL)
	{
		if (!handle_builtin(command))
		{
			command.com = getcomm(command);
			if (command.com != NULL)
				id = _execve(command);
			if (command.com == NULL && (!isatty(STDIN_FILENO)))
				return (127);
			free(command.com);
		}
	}
	free_pointers(command.arg, buf, NULL);
	buf = NULL;
	return (id);
}

/**
 * handle_builtin - search for match and execute the associate builtin
 * @command: command to be chacked
 * Return: 0 (success) or 1
*/
int handle_builtin(comd command)
{
	int i;
	builtin_t conv[] = {
		{"exit", bultin_exit},
		{"env", bultin_env},
		{NULL, NULL}
	};

	for (i = 0; conv[i].name != NULL; i++)
	{
		if (!_strcmp(command.arg[0], conv[i].name))
		{
			conv[i].func(command);
			return (1);
		}
	}
	return (0);
}
