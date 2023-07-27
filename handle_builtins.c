#include "shell.h"
#include <stdlib.h>

void handle_builtins(char *line, char **envp)
{
	int i = 0;

	if (_strcmp(line, "exit") == 0)
	{
		exit(0);
	}

	if (_strcmp(line, "env") == 0)
	{
		while (envp[i])
		{
			print(envp[i]);
			i++;
		}
	}
}
