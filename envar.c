#include "shell.h"

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
