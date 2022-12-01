#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * @env: pointer to pointer
 * Return: output
 */
int main(int ac, char **av, char **env)
{
	int status;
	char *lineptr = NULL, **PATH = NULL, *DIRE, *CONCAT;
	size_t n = 0;
	pid_t pid_child;
	struct stat buf;
	char **str;
	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(0))
			printf("$ ");
		if (getline(&lineptr, &n, stdin) == -1)
			break;
		str = split_line(lineptr);
		if (_strcmp(str[0], "exit\n") == 0)
		{
			free(str);
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(str[0], "env\n") == 0)
		{
			extern char **environ;
			char **s = environ;

			for (; *s; s++)
				printf("%s\n", *s);
			continue;
			free(str);
			continue;
		}
		else if (_strcmp(str[0], "stdin\n") == 0)
		{
			free(str);
			exit(0);
		}
		if (str[0] != NULL)
		{
			if (stat(str[0], &buf) == -1)
			{
				PATH = get_path(env);
				DIRE = getDir(PATH, str);
				if (DIRE != NULL)
					CONCAT = concat_str_dir(DIRE, str[0]);
			}
			else
				CONCAT = str[0];
			pid_child = fork();
			if (pid_child != 0)
			{
				wait(&status);
				free(str);
				str = NULL;
			}
			else
			{	
				if(execve(CONCAT, str, env))
				{	
						if (stat(str[0], &buf) == -1)
					{
							perror("execve");
					}
				}
			}
		}
	}
	free(lineptr);
	free(str);
	return (0);
}
