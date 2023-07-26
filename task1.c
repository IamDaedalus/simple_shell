#include "main.h"

/**
 * main - main entry of the program 
 * @ac: represent the argument count 
 * @env: the environment variable 
 *
 * Return: on success 0 and -1 on failure 
 */

int main(int ac, char **env)

{
	char *line_p = NULL;
	size_t n = 0;
	char *argv[MAX_CMND] = {NULL};
	int check, i, j;
	char *token;

	while (1)
	{
		if (isatty(STDOUT_FILENO))
		{
		write(1, "$", 1);
		}
		else 
		{
			if (getline(&line_p, &n, stdin) < 0)
			{
			free(line_p);
			exit(EXIT_FAILURE);

			}
		}
		
		check = getline(&line_p, &n, stdin);
        if (check < 0)
        {
            perror("getline failed\n");
            free(line_p);
            exit(EXIT_FAILURE);
        }

		int i = 0;
		while (line_p[i])
		{
			if (line_p[i] == '\n')
			{
			line_p[i] = 0;
			}
		i++;
	}
	if (strlen(line_p) == 0)
	{
		continue;
	}

	int j = 0;
	
	char *token = strtok(line_p, " ");
	
	while (token != NULL && j < MAX_CMND - 1)
	{
	argv[j] = strndup(token, strlen(token));	
	token = strtok(NULL, " ");
	
	j++;
	}
	
	argv[j] = NULL;
	
	if (strcmp(argv[0], "exit") == 0)
	
	{
		
		exit(EXIT_SUCCESS);

	}
return (0);
	}
}

