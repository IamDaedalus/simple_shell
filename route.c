#include "main.h"

/**                                                * route - specifies the root location
 * @cmnd: command passed by the user
 *
 * Return: The path sought or error if not found 
 */

char *get_route(char *cmnd)
{
	char *dir, *dir_cp, *tok_dir, *full_dir;
	int cmnd_len, dir_len;
	struct stat check;

	dir = getenv("PATH");
	dir_cp = strdup(dir);
	if (dir == NULL)
	{
		write(STDERR_FILENO, "Error: PATH environment variable not found.\n", 43);
		return (NULL);
	}
	cmnd_len = strlen(cmnd);
	tok_dir = strtok(dir_cp, ":");
	
	while (tok_dir)
	{
	dir_len = strlen(tok_dir);
	full_dir = malloc(cmnd_len + dir_len + 2);
	if (full_dir == NULL)
	{
		perror("Error: memory allocation failed.");
		free(dir_cp);
		return(NULL);
	
	strcpy(full_dir, tok_dir);
	strcat(full_dir, "/");
	strcat(full_dir, cmnd);

	if (stat(full_dir, &check) == 0)
	{
		free(dir_cp);
		return (full_dir);
	}

	else 
	{
		free(full_dir);
		tok_dir = strtok(NULL, ":");
	}
}
free(dir_cp);
if (stat(cmnd, &check) == 0)
{
	return (cmnd);
}
return (NULL);
}
}

