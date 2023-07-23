#include "main.h"

/**
* execve_check - function that execute program
* @argv: array of vectors argument
*
* Return: 0 on success and -1 on failure
*/

int execve_check(char **argv)
{
	pid_t pid;

if (argv[0] != NULL && access (argv[0], X_OK | F_OK) == 0)
{
pid = fork();
if (pid < 0)
{

perror("./hsh");
exit(EXIT_SUCCESS);
}


if (pid == 0)

{

int r_value = execve(argv[0], argv, environ);

if (r_value < 0)

perror("./hsh");
wait(EXIT_SUCCESS);
}

return (-1);

}

else
{

wait(NULL);

}
return (0);
}

