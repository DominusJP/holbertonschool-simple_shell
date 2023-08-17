#include "main.h"

/**
 * simple_tokenizer - Split the input string into a array of arguments (tokens)
 * @inputT: String from input (main function)
 * Return: Pointer to the array of tokens
 */
char **simple_tokenizer(char *inputT)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;
tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
	fprintf(stderr, "memory allocation error\n");
	exit(EXIT_FAILURE);
	}
	token = strtok(inputT, DELIM_I);
	while (token != NULL)
	{
	tokens[position] = token;
	position++;
	if (position >= buffer)
	{
	newBuffer = BUFSIZE * 2;
	backup_tokens = tokens;
	tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
	if (tokens == NULL)
	{
	free(backup_tokens);
	free(tokens);
	fprintf(stderr, "memory allocation error\n");
	exit(EXIT_FAILURE);
	}
	}
	token = strtok(NULL, DELIM_I);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * tokenizerPath - Split the environment variable PATH into an array of tokens
 * @inputT: Pointer to environment variable PATH
 * Return: Pointer to the array of tokens
 */
char **tokenizerPath(char *inputT)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;
tokens = malloc(buffer * sizeof(char *));
if (tokens == NULL)
	{
fprintf(stderr, "memory allocation error\n");
	exit(EXIT_FAILURE);
	}
	token = strtok(inputT, DELIM_P);
	while (token != NULL)
	{
	tokens[position] = token;
	position++;
	if (position >= buffer)
	{
	newBuffer = BUFSIZE * 2;
	backup_tokens = tokens;
	tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
	if (tokens == NULL)
	{
	free(backup_tokens);
	free(tokens);
	fprintf(stderr, "memory allocation error\n");
	exit(EXIT_FAILURE);
	}
	}
	token = strtok(NULL, DELIM_P);
	}
	tokens[position] = NULL;
	return (tokens);
}
