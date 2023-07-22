#include "shell.h"
#include <stdio.h>

/**
 * main - the entry point of C programs
 * @argc: number of command line args
 * @argv: each commandline argument as a str
 * @envp: the env variables for the system
 * Return: returns ret_val as indicated by init_shell
 */
int main(int argc, char **argv, char *envp[])
{
	char *path = _getenv(envp, "PATH");

	(void)argc;
	(void)argv;


	if (path != NULL) {
		printf("PATH: %s\n", path);
	} else {
		printf("PATH environment variable not found.\n");
	}


	/* return (init_shell(argv, envp)); */
	return (0);
}
