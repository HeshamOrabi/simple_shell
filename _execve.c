#include "main.h"

/**
 * _execve - execve command
 * @c: struct that have all what we need
 * Return: exit status of last procces id
 */
pid_t _execve(comd c)
{
	pid_t id;

	id = fork();
	if (id > 0)
	{
		wait(&id);
	}
	else
	{
		if (execve(c.com, c.arg, environ) == -1)
		{
			print_err_m(c.shell_name, c.com_count);
			perror("");
			exit(-1);
		}
	}
	return (id);
}
