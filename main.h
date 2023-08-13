#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#define BUFSIZE 64
#define DELIM_I " \t\n"
#define DELIM_P ":"

/**
 * struct elegir_builtin - Builtin commands struct
 * @name_builtin: Name of builtin command
 * @func_builtin: Pointer to builtin command functions
 */
typedef struct elegir_builtin
{
	char *name_builtin;
	int (*func_builtin)(char **, char *, int *);

} choose_builtins_t;
extern char **environ;
int main(int argCount, char **argVector);
char **simple_tokenizer(char *inputT);
char **tokenizerPath(char *inputT);
char *validateInput(char **arguments, char **argVector);
int validateSpaces(char *inputT);
int simple_execute(char **arguments, char **argv, int *exitStatus);
int simple_execute_builtins(char **args, char *input, char **argVector, int *exitStatus);
int simple_cd(char **args, char *inputStdin, int *exitStatus);
int simple_setenv(char **args,  char *input, int *exitStatus);
int simple_unsetenv(char **args,  char *input, int *exitStatus);
int simple_env(char **args, char *input, int *exitStatus);
int simple_exit(char **args, char *input, int *exitStatus);
void sigintH(int signum);
char *str_concat(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif /* SIMPLE_SHELL_H */
