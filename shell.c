#include "main.h"
/**
 * main - Entry point
 * @ac: ...
 * @av: ...
 * @env: ...
 * Return: ...
 */
int main(int ac, char **av, char **env)
{
	int status;
	char *lineptr = NULL;
	size_t n = 0;
	pid_t pid_child;
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
		}
		else if (_strcmp(str[0], "stdin\n") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			pid_child = fork();
			if (pid_child != 0)
				wait(&status);
			else
				execve(str[0], str, env);
		}
	}
	free(lineptr);
	free(str);
	return (0);
}
