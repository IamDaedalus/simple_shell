#include "shell.h"
#include <stdlib.h>

/**
 * handle_builtins - handles certain builtins
 * @args: the extracted args from the cmdline
 * @envp: local env
 */
void handle_builtins(char **args, char **envp)
{
	int exit_code = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
			exit_code = _atoi(args[1]);

		free(args[0]);
		exit(exit_code);
	}

	if (_strcmp(args[0], "env") == 0)
	{
		print_envvar(envp);
	}
}

/**
 * _atoi - converts a string to int
 * @str: the string
 * Return: returns the number
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	while (is_num(str[i]) == 1)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

/**
 * is_num - checks if a byte is a number
 * @c: the byte
 * Return: returns 1 for true and 0 for false
 */
int is_num(char c)
{
	return (c >= '0' && c <= '9');
}
