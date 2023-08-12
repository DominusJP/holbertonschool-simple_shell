#include "main.h"

int enSegundoPlano(char *path1, char *argv1, char *argv2, char *argv3)
{
	char *full_path;
	int archivo;

	path1 = strtok(path1, ":");
	while (path1)
	{
		if (!(full_path = malloc(1024)))
			return (-1);
		strcat(full_path, path1);
		strcat(full_path, "/");
		strcat(full_path, argv1);
		if ((archivo = open(full_path, O_RDONLY)) == 3)
		{
			close(archivo);
			char *argv[] = { full_path, argv2, argv3, NULL };
			execve(full_path, argv, NULL);
		}
		path1 = strtok(NULL, ":");
		free(full_path);
	}
	return (-1);
}

int main(int argCount, char **argVec, char **envVars)
{
	size_t bufsize = 1024;
	char *b;
	int textoUsuario;
	char *path = getenv("PATH");
	char *path1 = strdup(path);

	if (argCount > 1)
		return (enSegundoPlano(path1, argVec[1], argVec[2], argVec[3]));

	while(1)
	{
		if (!(b = malloc(bufsize)))
			return (-1);
		printf("#caritafeliz$ ");
		textoUsuario = getline(&b, &bufsize, stdin);

		free(b);
	}
	return (0);
}
