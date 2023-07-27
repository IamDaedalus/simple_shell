#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print - simple function that prints only text fed to it
 * @msg: the message to print
 */
void print(const char *msg)
{
	int i = 0;

	if (!msg)
	{
		return;
	}

	while (msg[i])
	{
		_putchar(msg[i]);
		i++;
	}
}

/**
 * extract_args - extracts arguments from the user's input
 * @line: the line the user typed
 * @args: the char * array that stores each argument
 * @max_args: the maximum args
 */
void extract_args(char *line, char *args[], int max_args)
{
	int i = 0;
	char *token;

	/*
	 * Split the line into tokens based on spaces
	 * tabs, and newline characters
	 */
	token = strtok(line, " \t\n");

	while (token != NULL && i < max_args - 1)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	/*
	 * Set the last element of the array to
	 * NULL to mark the end of arguments
	 */
	args[i] = NULL;
}

/**
 * _getenv - extracts the PATH variable from envp
 * @env: the environment variables
 * @var: the variable to check
 * Return: returns PATH or NULL if not found
 */
char *_getenv(char **env, char *var)
{
	int i = 0;

	if (!env)
		return (NULL);

	while (env[i])
	{
		if (_strncmp(env[i], var, 4) == 0)
			return (env[i]);

		i++;
	}

	return (NULL);
}

/**
 * get_cmd_path - checks and returns the full path to the command
 * if found
 * @args: the user's args from the shell
 * @envp: local environment variable
 * Return: returns the fullpath of the command or NULL if not found
 */
char *get_cmd_path(char *args[], char **envp)
{
	int i = 0, j = 0;
	char *path_entries[MAX_PATH_COUNT], *full_path = NULL;
	char *tok = NULL, *final = NULL;
	char *path = strdup(_getenv(envp, "PATH"));

	if (strchr(args[0], '/'))
		return (args[0]);

	if (path == NULL)
		return (NULL);

	tok = strtok(path, "=");
	while (tok != NULL && i < MAX_PATH_COUNT)
	{
		path_entries[i] = tok;
		i++;
		tok = strtok(NULL, ":");
	}
	path_entries[i] = NULL;

	/* iterate through each entry looking for the command */
	for (j = 0; path_entries[j] != NULL; j++)
	{
		full_path = malloc(_strlen(path_entries[j]) + _strlen(args[0]) + 2);
		if (full_path == NULL)
			return (NULL);

		_strcpy(full_path, path_entries[j]);
		_strcat(full_path, "/");
		_strcat(full_path, args[0]);

		if (access(full_path, F_OK) == 0)
		{
			final = full_path;
			break;
		}
		free(full_path);
	}

	return (final);
}
