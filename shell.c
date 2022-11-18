#include "main.h"
/**
 * main - Entry point
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
		if (_strcmp(lineptr, "exit\n") == 0)
		{
			exit(0);
		}
		str = split_line(lineptr);
		if (str[0] != NULL)
		{
			pid_child = fork();
			if (pid_child != 0)
			{
				wait(&status);
			}
			else
				execve(str[0], str, env);
		}
		if (_strcmp(lineptr, "pwd\n") == 0)
		{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			printf("%s", cwd);
			printf("\n");
		}
		if (_strcmp(lineptr, "env\n") == 0)
		{
			extern char **environ;
			char **s = environ;

			for (; *s; s++)
			{
				printf("%s\n", *s);
			}
		}
	}
	return (0);
}
