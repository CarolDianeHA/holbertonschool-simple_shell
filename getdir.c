#include "main.h"
/**
 * getDir - function parses through path array, opens all directories,
 * and checks if files exist
 *
 * @patharray: array of directories in the path
 * @commandlineArgs: user input
 *
 * Return: directory 
 */

char *getDir(char **patharray, char **commandlineArgs)
{
	DIR *directory = NULL;
	struct dirent *structdir = NULL;
	int count;

	for (count = 0; patharray[count] != NULL; count++)
	{
		directory = opendir(patharray[count]);
		if (directory == NULL)
			return (NULL);

		while ((structdir = readdir(directory)) != NULL)
		{
			if (_strcmp(structdir->d_name, commandlineArgs[0]) == 0)
			{
				closedir(directory);
				return (patharray[count]);
			}
		}
		closedir(directory);
	}

	return (NULL);
}
