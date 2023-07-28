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
