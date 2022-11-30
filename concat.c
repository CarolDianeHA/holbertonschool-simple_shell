#include "main.h"

/**
 * concat_str_dir - concat token and value
 * @array: token
 * @command: value
 * Return: new string
 */

char *concat_str_dir(char *array, char *command)
{
	char *new;
	char *final;

	new = strcat(array, "/");
	final = strcat(new, command);

	return (final);
}
