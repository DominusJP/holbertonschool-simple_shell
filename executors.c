#include "main.h"

/**
 * simple_execute - Fork process and replace the child with a new program
 * @arguments: String of arguments (tokens)
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: Always 1 (success).
 */
int simple_execute(char **arguments, char **argVector, int *exitStatus)
{
	pid_t pid;
	int status;
	char *new_arguments;
	new_arguments = validateInput(arguments, argVector);
	if (strcmp(new_arguments, "Fail access") == 0)
	return (1);
	pid = fork();
	if (pid == 0)
	{
	if (execve(new_arguments, arguments, environ) == -1)
	{
	perror("execve fail");
	exit(EXIT_FAILURE);
	}
	}
	else if (pid < 0)
	{
	perror("Error forking");
	free(new_arguments);
	return (1);
	}
	else
	{
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
	*exitStatus = WEXITSTATUS(status);
	if (arguments[0][0] != '/' && arguments[0][0] != '.')
	free(new_arguments);
	return (1);
	}
	return (1);
}

/**
 * simple_execute_builtins - Choose from an array of builtin functions
 * @args: String of arguments (tokens)
 * @input: String from user
 * @argVector: Array of arguments
 * @exitStatus: Exit status
 * Return: Status to stay or exit the main loop, 1 or 0
 */
int simple_execute_builtins(char **args, char *input, char **argVector, int *exitStatus)
{
	int i = 0;
	choose_builtins_t options[] = {
		{"exit", simple_exit},
		{"env", simple_env},
		{"cd", simple_cd},
		{"setenv", simple_setenv},
		{"unsetenv", simple_unsetenv},
		{NULL, NULL}
	};
	while (options[i].name_builtin)
	{
	if (strcmp(options[i].name_builtin, args[0]) == 0)
	{
	return ((int)((*options[i].func_builtin)(args, input, exitStatus)));
	}
	i++;
	}
	return (simple_execute(args, argVector, exitStatus));
}
