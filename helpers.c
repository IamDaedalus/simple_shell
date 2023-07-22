#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * print - simple function that prints only text fed to it
 * @msg: the message to print
 */
void print(char *msg)
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
