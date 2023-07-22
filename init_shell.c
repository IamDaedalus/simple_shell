#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>

int init_shell(void)
{
	pid_t kid_proc;
	int status, ret_val = 0;
	char *line = NULL;
	size_t line_size = 0;
	char *args[30];

	while (1)
	{
		print(PROMPT);

		if ((getline(&line, &line_size, stdin)) == -1)
		{
			break;
		}

		if (line[0] == '\n')
			continue;

		extract_args(line, args, 30);

		kid_proc = fork();
		if (kid_proc < 0)
		{
			perror("Error");
		}
		else if (kid_proc == 0)
		{
			if ((execve(args[0], args, NULL)) == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}

		free(line);
		line_size = 0;
	}

	free(line);

	return (ret_val);
}
