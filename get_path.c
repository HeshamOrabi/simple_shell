#include "main.h"

/**
 * is_delim - function to check the delim.
 * @c: char in string.
 * @delim: a pointer to the delimiter string.
 * Return: returns 0 or 1
*/
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - a function breaks a string into a tokens
 * @src_string: a pointer to the string.
 * @delim: a pointer to the delimiter string.
 * Return: returns a pointer
*/
char *_strtok(char *src_string, char *delim)
{
	static char *backup_string;
	char *ret;

	if (!src_string)
	{
		src_string = backup_string;
	}
	if (!src_string)
	{
		return (NULL);
	}
	while (1)
	{
		if (is_delim(*src_string, delim))
		{
			src_string++;
			continue;
		}
		if (*src_string == '\0')
		{
			return (NULL);
		}
		break;
	}
	ret = src_string;
	while (1)
	{
		if (*src_string == '\0')
		{
			backup_string = src_string;
			return (ret);
		}
		if (is_delim(*src_string, delim))
		{
			*src_string = '\0';
			backup_string = src_string + 1;
			return (ret);
		}
		src_string++;
	}
}

/**
 * _getenv - a function that gets an environment variable
 * @name: the enviroment name
 * Return: returns a pointer to the value in
 * the environment, or NULL if there is no match.
*/
char *_getenv(char *name)
{
	char *ret_token;

	while (*environ)
	{
		char *envVar = _strdup(*environ);
		char *token = _strtok(envVar, "=");

		if (_strcmp(token, name) == 0)
		{
			token = _strtok(NULL, "\n");
			ret_token = _strdup(token);
			free(envVar);
			return (ret_token);
		}
		free(envVar);
		environ++;
	}
	return (NULL);
}

/**
 * getcomm - a function that gets a file direactory
 * @c: the structure of the command
 * Return: filepath or null
*/
char *getcomm(comd c)
{
	char *token, *path, *fullpath;
	int lencomm = _strlen(c.com), lenpath;
	struct stat statbuf;

	if (stat(c.com, &statbuf) == 0)
		return (_strdup(c.com));
	path = _getenv("PATH");
	if (path)
	{
		token = _strtok(path, ":");
		while (token)
		{
			lenpath = _strlen(token);
			fullpath = malloc(lencomm + lenpath + 2);
			_memcpy(fullpath, token);
			_strcat(fullpath, "/");
			_strcat(fullpath, c.com);
			_strcat(fullpath, "\0");

			if (!stat(fullpath, &statbuf))
			{
				free(path);
				return (fullpath);
			}
			free(fullpath);
			token = _strtok(NULL, ":");
		}
	}
	free(path);
	not_found(c.shell_name, c.com_count, c.com);
	return (NULL);
}
