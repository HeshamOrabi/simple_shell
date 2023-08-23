#include "main.h"
/**
 * get_tokens - make the argument tokens
 * @buf: the buffered input
 *
 * Return: argument vector array of strings
*/
char **get_tokens(char *buf, char *av)
{
	char **argv;
	char *cpy_buf;
	int tokens = 1, i, del = 0;
	char delimeters[] = {' ', '\t', '\n'};

	cpy_buf = malloc(strlen(buf) + 1);
	if (!cpy_buf)
	{
		perror(av);
		exit (-1);
	}
	_strcpy(cpy_buf, buf);
	strtok(cpy_buf, delimeters);
	while (strtok(NULL, delimeters))
		tokens++;
	argv = malloc(sizeof(char *) * (tokens + 1));
	if (!argv)
	{
		perror(av);
		exit(-1);
	}
	argv[0] = cpy_buf;
	for (i = 1; i < tokens; del++)
	{
		if (cpy_buf[del] == '\0')
		{
			del++;
			argv[i] = &cpy_buf[del];
			i++;
		}
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * _get_argv - make the argument vector
 * @buf: the buffered input
 *
 * Return: argumet vector array of strings
*/

f_cmd _get_argv(char *buf, char *av)
{
	f_cmd cmd;
	char **argv;
	int i = 0;

	argv = get_tokens(buf, av);
	cmd.cmd = argv[0];
	cmd.args = argv;
	if (!cmd.cmd || !cmd.args)
	{
		perror(av);
		exit(-1);
	}
	while (argv[i] != NULL)
	{
		cmd.args[i] = argv[i];
		i++;
	}
	cmd.args[i] = NULL;
	return (cmd);
}
