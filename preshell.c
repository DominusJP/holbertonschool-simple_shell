#include "main.h"

int main(int arg_count, char **arg_vector, char **env)
{
	size_t sizeMemoria = 256;
	char buffer[sizeMemoria];
	char *b = buffer;
	int textoUsuario;
	char *path = getenv("PATH");
	char *path1 = strdup(path);
	int archivo;
	char *full_path;
	if (arg_count > 1)
	{
		path1 = strtok(path1, ":");
		while (path1)
		{
			if (!(full_path = malloc(1024)))
				return(0);
			strcat(full_path, path1);
			strcat(full_path, "/");
			strcat(full_path, arg_vector[1]);
			if ((archivo = open(full_path, O_RDONLY)) == 3)
			{
				char *argv[] = { full_path, arg_vector[2] };
				execve(full_path, argv, NULL);
			}
			close(archivo);
			path1 = strtok(NULL, ":");
			free(full_path);
		}
		return (0);
	}

	while(1)
	{
		printf("caritaFeliz($) ");
		textoUsuario = getline(&b, &sizeMemoria, stdin);
	}
	return (0);
}
