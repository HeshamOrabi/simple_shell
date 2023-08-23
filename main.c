#include "main.h"

/**
 * main - a simple shell
 * Return: returns 0 on success
 */

int main(int ac, char **argv, char**envp)
{
	f_cmd cmd;
	char *buf;
	size_t buff_size;

	if (ac >= 0)
	{
		while (1)
		{
			buf = NULL;

			print_prompt();
			get_input(&buf, &buff_size);
			cmd = _get_argv(buf, argv[0]);
			cmd.buffer = buf;
			cmd.cmd = _which(cmd.cmd);
			if (!check_empty_str(cmd.cmd))
				_execv(cmd.cmd, cmd.args, argv[0], envp);
			else
				perror(argv[0]);
			
			free(cmd.cmd);
		}
	}
	return (0);
}
