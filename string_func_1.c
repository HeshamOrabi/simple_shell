#include "main.h"

/**
 * _strlen - a function that returns string length.
 * @str: the string.
 * Return: returns string length.
*/
ssize_t _strlen(const char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0';)
		i++;
	return (i);
}

/**
 * _memcpy - a function that copies memory area.
 * @dest: an array that will fill.
 * @src: an array that will copy from
 * Return: returns a pointer to dest.
*/
char *_memcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: given string
 *
 * Return: a pointer to memory space with the copy of the string
 * or exit with value -1 if failed.
*/

char *_strdup(char *str)
{
	int i;
	char *dup = malloc(_strlen(str) + 1);

	if (dup == NULL)
	{
		perror("Error");
		exit(-1);
	}
	for (i = 0; str[i] != '\0'; i++)
		*(dup + i) = *(str + i);
	*(dup + i) = *(str + i);
	return (dup);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: returns a pointer
*/
char *_strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

/**
 * _strcmp - a function that comapre between two strings
 * @s1: first string
 * @s2: second string
 * Return: returns 0 if they are same.
*/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
