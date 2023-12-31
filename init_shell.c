#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>


/**
 * init_shell - starting point for the shell
 * @argv: the arg vectors from main
 * @envp: the env variablea from main
 * Return: returns -1 for failure or 0 for success
 * which is then passed to main function
 */
int init_shell(char **argv, char **envp)
{
	pid_t child_proc;
	char *line = NULL, *cmd_path = NULL;
	size_t line_size = 0;
	char *args[30];
	int ret_val = 0, tty = isatty(STDIN_FILENO);

	while (1)
	{
		if (tty) /* this is the modification made */
			print(PROMPT);

		/* handle empty lines and ctrl d */
		if ((getline(&line, &line_size, stdin)) == -1)
			break;

		if (handle_empty(line) == 0)
			continue;

		extract_args(line, args, 30);
		if (_strcmp(args[0], "\n") == 0)
			continue;

		handle_builtins(args, envp);
		cmd_path = get_cmd_path(args, envp);
		if (cmd_path == NULL)
			perror(argv[0]);
		else
		{
			args[0] = _strdup(cmd_path);
			free(cmd_path);
			child_proc = fork();
			if ((core_logic(child_proc, args, argv, envp)) == -1)
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
 * @argv: we need this for accessing the binary name
 * @envp: the env variable
 * Return: returns 0 for success or -1 otherwise
 * and is passed to init_shell which in turn passes to main
 */
int core_logic(pid_t child, char *args[], char **argv, char **envp)
{
	int ret_val = 0, status;

	if (child < 0)
	{
		/* print the name of the binary and an error */
		perror(argv[0]);
		return (-1);
	}
	else if (child == 0)
	{
		if ((run_command(args, envp)) == -1)
		{
			perror(argv[0]);
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}

	free(args[0]);
	return (ret_val);
}

/**
 * run_command - execve wrapper
 * @args: the extracted args from the prompt
 * @envp: the environment vars from main()
 * Return: returns 0 for success or -1 for failure
 */
int run_command(char *args[], char **envp)
{
	(void)envp;
	return (execve(args[0], args, environ));
}

/**
 * handle_empty - handles every empty input (almost)
 * @line: the user's input
 * Return: code for execution
 */
int handle_empty(char *line)
{
	int i = 0;

	if (line[0] == '\n')
		return (0);

	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}

	return (0);
}
