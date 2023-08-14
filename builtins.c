#include "main.h"

/**
 * simple_cd - Change directory
 * @args: Array of tokens
 * @input: Input from user
 * @exitStatus: Exit
 * Return: 1 (success)
 */
int simple_cd(char **args, char *input, int *exitStatus)
{
	int stat;
	char s[128];
	getcwd(s, sizeof(s));
	(void)input;
	(void)exitStatus;
	if (args[1] == NULL)
	stat = chdir(getenv("HOME"));
	else if (strcmp(args[1], "-") == 0)
	stat = chdir(getenv("OLDPWD"));
	else if (strcmp(args[1], "~") == 0)
	stat = chdir(getenv("HOME"));
	else
	stat = chdir(args[1]);
	if (stat == -1)
	perror("error whenm executing cd, please try again");
	setenv("OLDPWD", s, 1);
	setenv("PWD", getcwd(s, sizeof(s)), 1);
	return (1);
}

/**
 * simple_setenv - Change or add and environment variable
 * @args: Array of tokens from input
 * @input: Input from user
 * @exitStatus: Exit
 * Return: Return 1 if use a function, 0 otherwise.
 */
int simple_setenv(char **args,  char *input, int *exitStatus)
{
	int nTokens = 0;
	(void)input;
	(void)exitStatus;
	while (args[nTokens] != NULL)
	{
	nTokens++;
	}
	if (nTokens == 3)
	setenv(args[1], args[2], 1);
	else if (nTokens != 3)
	fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");
	return (1);
}

/**
 * simple_unsetenv - Delete an environmental variable
 * @args: Array of tokens from input
 * @input: Input from user
 * @exitStatus: Exit
 * Return: Return 1 if use a function, 0 otherwise.
 */
int simple_unsetenv(char **args,  char *input, int *exitStatus)
{
	int nTokens = 0;
	(void)input;
	(void)exitStatus;
	while (args[nTokens] != NULL)
	{
	nTokens++;
	}
	if (nTokens == 2)
	unsetenv(args[1]);
	else if (nTokens != 2)
	fprintf(stderr, "Try use \"unsetenv [KEY]\"\n");
	return (1);
}

/**
 * simple_env - Function to print the enviromental
 * @args: arguments
 * @input: input of the user
 * @exitStatus: exit
 * Return: Always 1 (success)
 */
int simple_env(char **args, char *input, int *exitStatus)
{
	int i = 0;
	(void)args;
	(void)input;
	(void)exitStatus;
	if (environ[i] == NULL)
	{
	printf("%s", "The built in env is empty");
	return (1);
	}
	for (i = 0; environ[i]; i++)
	printf("%s\n", environ[i]);
	return (1);
}

/**
 * simple_exit - Function to exit the shell
 * @args: arguments
 * @input: input of the user
 * @exitStatus: exit status
 * Return: Exit success
 */
int simple_exit(char **args, char *input, int *exitStatus)
{
	int outputExit = 0;
	(void)args;
	(void)input;
	(void)exitStatus;
	if (args[1] == NULL)
	{
	free(args);
	free(input);
	exit(*exitStatus);
	}
	if (args[2] != NULL)
	{
	fprintf(stderr, "just wrtite: exit\n");
	return (0);
	}
	outputExit = atoi(args[1]);
	free(args);
	free(input);
	exit(outputExit);
}
