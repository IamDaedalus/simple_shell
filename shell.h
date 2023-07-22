#ifndef SHELL_H
#define SHELL_H

#define PROMPT "cisfun$ "

void print(char *msg);
int _putchar(char c);
void extract_args(char *line, char *args[], int max_args);
int init_shell(void);

#endif /* SHELL_H */
