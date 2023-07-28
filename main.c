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
	(void)argc;
	/*
	 * char *cmd = "    \n";
	 * char *args[2] = { "      \n", NULL };
	 * (void)argc;
	 * (void)argv;
	 * run_command(args, envp);
	 * return 0;
	*/
	return (init_shell(argv, envp));
}
