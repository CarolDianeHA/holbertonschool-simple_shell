#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int _putchar(char c);
int _strcmp(char *s1, char *s2);
char **split_line(char *lineptr);
char *concat_str_dir(char *array, char *command);
char **get_path(char **env);
char *getDir(char **path, char **command);
#endif
