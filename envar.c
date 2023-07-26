#include "main.h"

/**
 * print_envvar - function that print env variabl
 *
 * Return: env variable on success & -1 on failure
 */

void print_envvar(void)
{
	int dex = 0;

	while (environ[dex])
	{
		write(STDOUT_FILENO, environ[dex], strlen(environ[dex]));
		write(STDOUT_FILENO, "\n", 1);
	}
	dex++;
}
