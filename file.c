#include "main.h"
/**
*main -  main entry of the program
*Return: always 0 on success & -1 on failure
*/
int main(void)
{
char *line_p = NULL;
int check, status, i, j;
size_t n = 0;
char *argv[MAX_CMND] = {NULL};
int from_pipe = 0;
int spining = 1;
if (isatty(STDOUT_FILENO) == 0)
from_pipe = 1;
while (spining && !from_pipe)
{
write(STDOUT_FILENO, "$", 1);
while  ((check = getline(&line_p, &n, stdin)) != -1)
{
spining = 0;
write(3, "Exiting shell...\n", 18);
break;
}
line_p[check - 1] = '\0';
i = 0;
while (line_p[i])
{
if (line_p[i] == '\n')
line_p[i] = '\0';
i++;
}
if (strlen(line_p) == 0)
{
continue;
}
j = 0;
char *token = strtok(line_p, " ");
while (token != NULL && j < MAX_CMND - 1)
{
argv[j] = malloc(sizeof(strlen(token) + 1));
strcpy(argv[j], token);
token = strtok(NULL, " ");
j++;
}
argv[j] = NULL;
}
if (strcmp(argv[0],  "exit") == 0)
{
exit(EXIT_SUCCESS);
}
}
