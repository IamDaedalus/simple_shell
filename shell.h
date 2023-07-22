#ifndef SHELL_H
#define SHELL_H

#define PROMPT "#cisfun$ "

#include <unistd.h>

void print(const char *msg);
int _putchar(char c);
void extract_args(char *line, char *args[], int max_args);
int init_shell(char **argv, char **envp);
int core_logic(pid_t child, char *args[], char **argv, char **environ);
void clear_residuals(char **line, size_t *line_size);
char *_getenv(char **envp, char *var);

#endif /* SHELL_H */
