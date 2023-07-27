#ifndef SHELL_H
#define SHELL_H

#define PROMPT "#cisfun$ "
#define MAX_PATH_COUNT 64

#include <unistd.h>

void print(const char *msg);
int _putchar(char c);
void extract_args(char *line, char *args[], int max_args);
int init_shell(char **argv, char **envp);
int core_logic(pid_t child, char *args[], char **argv, char **environ);
void clear_residuals(char **line, size_t *line_size);
char *_getenv(char **envp, char *var);
int run_command(char *args[], char **envp);
char *get_cmd_path(char *args[], char **envp);
int handle_empty(char *line);

/* STRING HELPERS */
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *source);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);

#endif /* SHELL_H */
