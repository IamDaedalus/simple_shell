#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

/**
 * init_shell - starting point for the shell
 */
int init_shell(char **argv, char **envp)
{
	pid_t kid_proc;
	int ret_val = 0;
	char *line = NULL;
	size_t line_size = 0;
	char *args[30];

	while (1)
	{
		print(PROMPT);
		fflush(stdout);

		if ((getline(&line, &line_size, stdin)) == -1)
		{
			break;
		}

		if (line[0] == '\n')
			continue;

		extract_args(line, args, 30);

		kid_proc = fork();
		if ((core_logic(kid_proc, args, argv, envp)) == -1)
		{
			/* break as soon as something fails in core_logic */
			break;
		}

		clear_residuals(&line, &line_size);
	}
	clear_residuals(&line, &line_size);

	return (ret_val);
}

/**
 * clear_residuals - this function clears any remaining data upon exit
 * @line: free the user's input
 * @line_size: resets the line size or buffer to 0
 */
void clear_residuals(char **line, size_t *line_size)
{
	if (!line || !line_size)
		return;

	free(*line);
	*line_size = 0;
	fflush(stdout);
}

/**
 * core_logic - handles the executions of programs
 * @child: the child pid that was forked
 * @args: the args the user specified
 * @environ: the env variable
 * Return: returns 0 for success or -1 otherwise
 * and is passed to init_shell which in turn passes to main
 */
int core_logic(pid_t child, char *args[], char **argv, char **environ)
{
	int ret_val = 0, status;

	if (child < 0)
	{
		perror(argv[0]);
		return (-1);
	}
	else if (child == 0)
	{
		if ((execve(args[0], args, environ)) == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}

	return (ret_val);
}
