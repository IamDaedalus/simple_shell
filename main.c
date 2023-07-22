#include "shell.h"

/**
 * main - the entry point of C programs
 * Return: returns ret_val as indicated by init_shell
 */
int main(int argc, char **argv, char *envp[])
{
	int ret_val = init_shell(argv, envp);

	(void)argc;

	return (ret_val);
}
