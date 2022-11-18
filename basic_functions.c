#include "main.h"
/**
 * _strcmp - Function that compares 2 strings character by character.
 * @s1: char 1
 * @s2: char 2
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int x;

	while (s1[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			x = s1[i] - s2[i];
			return (x);
		}
		else if (s1[i] < s2[i])
		{
			x = s1[i] - s2[i];
			return (x);
		}
		i++;
	}
	return (0);
}
