#include "shell.h"
#include <stdlib.h>

/**
 * print_envvar - function that print env
 *@envp: Local environment variable
 * Return: env variable
 */

void print_envvar(char **envp)
{
	int dex = 0;

	while (envp[dex])
	{
		write(STDOUT_FILENO, envp[dex],	_strlen(envp[dex]));
		write(STDOUT_FILENO, "\n", 1);
		dex++;
	}
}

/**
 * _strdup - duplicates a string str
 * @str: the string to duplicate
 * Return: returns the new and duplicated string
 */
char *_strdup(const char *str)
{
	char *result = NULL;
	size_t len = 0;
	int i = 0;

	if (!str)
		return (NULL);
	len = _strlen(str);
	result = malloc(sizeof(char) * len + 1);


	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}

	return (result);
}

/**
 * _strchr - checks for the first occurence of c in str
 * @str: the string to run the check in
 * @ch: the character to check
 * Return: returns str if ch is found
 */
char *_strchr(const char *str, int ch)
{
	int i = 0;

	if (!str)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			return ((char *)str);
		}
		i++;
	}

	return (NULL);
}
