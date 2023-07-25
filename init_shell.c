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
	pid_t kid_proc;
	int ret_val = 0;
	char *line = NULL, *cmd_path = NULL;
	size_t line_size = 0;
	char *args[30];

	while (1)
	{
		print(PROMPT);
		fflush(stdout);

		/* handle empty lines and ctrl d */
		if ((getline(&line, &line_size, stdin)) == -1)
		{
			break;
		}

		if (line[0] == '\n')
			continue;

		extract_args(line, args, 30);
		cmd_path = get_cmd_path(args, envp);
		if (cmd_path == NULL)
		{
			perror(argv[0]);
		}
		else
		{
			args[0] = cmd_path;
			kid_proc = fork();
			if ((core_logic(kid_proc, args, argv, envp)) == -1)
			{
				/* break as soon as something fails in core_logic */
				break;
			}
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
	if ((execve(args[0], args, envp)) == -1)
	{
		return (-1);
	}

	return (0);

}

/*
 * check_file - this checks if the command exist by checking each PATH entry
 * @command: the entered command
 */
int check_file(char *command, char **envp)
{
	char *paths[MAX_PATH_COUNT];
	char *path = strdup(_getenv(envp, "PATH"));
	char *tok = NULL;
	int i = 0, j = 0;
	int ret_val = 0;

	if (!command)
		return (-1);

	/*check if the command is contains the path so we dont appens */
	if (strchr(command, '/'))
	{
		return (access(command, X_OK | F_OK));
	}
	else
	{
		tok = strtok(path, "=");
		while (tok)
		{
			tok = strtok(NULL, ":");
			paths[i] = tok;
			i++;
		}

		/* Null-terminate the paths array */
		paths[i] = NULL;

		/* Search for the binary in each directory path */
		while (path[j])
		{
			char *full_path = malloc(strlen(paths[j]) + strlen(command) + 2);
			if (full_path == NULL)
			{
				return (-1);
			}
			strcpy(full_path, paths[j]);
			strcat(full_path, "/");
			strcat(full_path, command);

			if ((access(full_path, X_OK | F_OK)) == -1)
			{
				/* this here prevented some leaks lol */
				free(full_path);
				/* 
				 * by setting retval here if we dont find the file we 
				 * can return the error code easily 
				 * */
				ret_val = -1; 
				j++;
			}
		}
	}

	return (ret_val);
}
