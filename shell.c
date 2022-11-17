#include "main.h"
/**
 * main - Entry point
 */
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;

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
		if (_strcmp(lineptr, "pwd\n") == 0)
		{
			char cwd[1024];
			getcwd(cwd, sizeof(cwd));
			printf("%s", cwd);
			printf("\n");
		}
	}
	return (0);
}
