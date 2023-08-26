#include "main.h"

/**
 * main - initializing shell
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 of succes
*/
int main(int __attribute__((unused)) argc, char **argv)
{

	if (!isatty(STDIN_FILENO))
	{
		handel_pipe(argv);
	}
	else
	{
		while (1)
			handel_interactive(argv);
	}
	return (0);
}
