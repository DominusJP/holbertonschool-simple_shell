#include "main.h"

/**
 * @input: Input from the user
 * @exitStatus: ExitStatus
 * Return: 1 (success)
 */

int main(int argCount __attribute__((unused)), char **argVector __attribute__((unused)))
{
    char **arguments = NULL;
    char *input = NULL;
    int statusReturn = 1, exitStatus = 0;
    size_t size = 0;
    ssize_t n = 0;

    while (statusReturn && n != EOF)
    {
        size = 0;
        statusReturn = isatty(STDIN_FILENO);
        if (statusReturn)
            write(STDOUT_FILENO, "#caritaFeliz$ ", 15);
        signal(SIGINT, sigintH);
        n = getline(&input, &size, stdin);
        if (n == -1)
        {
            free(input);
            break;
        }
        if (validateSpaces(input))
        {
            free(input);
            continue;
        }
        arguments = token(input);
        if (*arguments[0] == '\0')
            continue;
        statusReturn = builtins(arguments, input,
                argVector, &exitStatus);
        free(input);
        free(arguments);
    }
    return (0);
}

