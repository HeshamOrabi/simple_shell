#include "main.h"

/**
* _strlen - a function that returns string length.
* @str: the string.
* Return: returns string length.
*/
int _strlen(const char *str)
{
	if (!*str || !str)
		return (0);
	return (1 + _strlen(str + 1));
}

/**
 * _strcpy - a function that copies a string
 * @dest: first string
 * @src: second string
 * Return: returns a pointer
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
/**
 * chech_empty_str - check if the string is empty
 * empty means there is no chars only spaces or new line or tabs
 * @str: the string to check
 * Return: 1 if empty
 * or 0 if not empty
 * or -1 if NULL passed
 */

int check_empty_str(char *str)
{
	int i;

	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			return (0);
	}
	return (1);
}
