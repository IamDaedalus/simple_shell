#include "main.h"

/**
 * execve - A function that executr a program 
 * @argx: represent the argument count 
 *
 * Return: nothing on success and -1 on failure 
 */

int my_execve()
{      
	int check;
	pid_t pid;
	char *prog_name = "./hsh";

        if (access(prog_name, F_OK | X_OK) == 0)            {
                pid = fork();
		if (pid < 0)
		perror(prog_name);
                if (pid > 0)
                {
                        wait(NULL);
		}
		execve(prog_name, &prog_name, environ);
	       if (check > 0 || check < 0)
	       {
	perror(prog_name);
	       return (-1);
	       }
return (0);
	}
}
