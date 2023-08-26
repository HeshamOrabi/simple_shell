#include "main.h"

/**
 * not_found - print not_fount to stderr
 * @shell_name: the shell name
 * @c: the comulative number of given commands
 * @cmd: the command
 */
void not_found(char *shell_name, int c, char *cmd)
{
	char num[1];

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	while (c % 10 != 0)
	{
		num[0] = (c % 10) + '0';
		c /= 10;
		write(STDERR_FILENO, num, 1);
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", _strlen(": not found\n"));
}

/**
 * print_err_m - print error
 * @shell_name: the shell name
 * @c: the number of command
 */
void print_err_m(char *shell_name, int c)
{
	char dig[1];

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	while (c % 10 != 0)
	{
		dig[0] = (c % 10) + '0';
		c /= 10;
		write(STDERR_FILENO, dig, 1);
	}
	write(STDERR_FILENO, ": ", 2);
}

