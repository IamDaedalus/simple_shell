#include "main.h"

/**
 * exit_prog - A function that exit a program 
 * @argvs: Argument vector 
 * @quit_code: exit the status when matched 
 *
 * Return: absolutely nothing 
 */

void exit_prog(char **argvs, int quit_code)
{
	int check;
	char *err_messg = "invalid argument:";
	if (argvs[1] == NULL)
	{
		exit(quit_code);
	}
	else 
	{
		check = atoi(argvs[1]);
		if (check == 0 && strcmp(argvs[1],"0") != 0)
write(2, err_messg, strlen(err_messg));
		write(2, argvs[1], strlen(argvs[1]));
		write(2, "\n", 1);
		exit(1);
	}
	free(argvs[0]);
	free(argvs[1]);
	free(argvs);
	exit(check);
}
