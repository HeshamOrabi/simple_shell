#include "main.h"

/**
 * get_command - print a initial func
 * @buf: the command
 * @bufsize: a pointer to the buffer size created for the line
 */
void get_command(char **buf, size_t *bufsize)
{
	char init[] = "($) ";
	int ilen = _strlen(init);
		char fin[] = "^C\n";
	int ifin = _strlen(fin);
	ssize_t bufl;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, init, ilen);
	bufl = getline(buf, bufsize, stdin);
	if (bufl == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, fin, ifin);
		free(*buf);
		exit(127);
	}
}

/**
 * get_buf - get buf from prompt or stdin
 * @buf: a pointer to the comand str
 * @bufsize: a pointer to the buffer size created for the line
 * Return: number of chars of the cmd line
 */
void get_buf(char **buf, size_t *bufsize)
{
	ssize_t bufl;

	bufl = getline(buf, bufsize, stdin);
	if (bufl == -1)
	{
		free(*buf);
		exit(0);
	}
}

/**
 * initialize_command - initializes the command structure
 * @c: pointer to the command structure
 * @buf: pointer to buf
 * @count: number of executed command
 * @argv: argument vector string
 */
void initialize_command(comd *c, char *buf, int count, char *argv[])
{
	c->path = buf;
	c->com_count = count;
	c->shell_name = argv[0];
}
/**
 * get_args - seprate command into sections
 * @buf: command to be split
 * Return: structure contain command details
 */
comd get_args(char *buf)
{
	comd strc;

	strc.arg = gen_token(buf);
	strc.com = strc.arg[0];
	return (strc);
}

/**
 * gen_token - seprate command into sections (tokens)
 * @buf: the buffer to seprate
 * Return: a array of strings
 */
char **gen_token(char *buf)
{
	char *token, *bufcopy;
	int tcount = 0;
	char **av;
	int i;
	char delim[] = {' ', '\t', '\n'};

	bufcopy = malloc(_strlen(buf) + 1);
	if (!bufcopy)
	{
		perror("Error");
		exit(-1);
	}
	_memcpy(bufcopy, buf);

	if (_strtok(bufcopy, delim) != NULL)
		tcount = 1;
	while (_strtok(NULL, delim))
		tcount++;

	av = malloc(sizeof(char *) * (tcount + 1));
	if (!av)
	{
		perror("Error");
		exit(-1);
	}

	if (tcount == 0)
		av[0] = NULL;
	else
	{
		token = _strtok(buf, delim);
		av[0] = token;
		for (i = 1; i < tcount; i++)
			av[i] = _strtok(NULL, delim);
		av[i] = NULL;
	}
	free(bufcopy);
	return (av);
}
