# Project Description

This project consists in write a simple UNIX command interpreter.

## General Concepts

* Unix shell
* Thompson shell
* Ken Thompson
* Everything you need to know to start coding your own shell
* Team work
* Github contribution

## Output

* Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)

Example of error with `sh`:
```sh
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program `hsh`:
```hsh
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## List of functions and system calls

<!-- * `access` (man 2 access) -->
<!-- * `chdir` (man 2 chdir) -->
<!-- * `close` (man 2 close) -->
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
<!-- * `_exit` (man 2 _exit) -->
<!-- * `fflush` (man 3 fflush) -->
* `fork` (man 2 fork)
* `free` (man 3 free)
<!-- * `getcwd` (man 3 getcwd) -->
* `getline` (man 3 getline)
<!-- * `getpid` (man 2 getpid) -->
* `isatty` (man 3 isatty)
<!-- * `kill` (man 2 kill) -->
* `malloc` (man 3 malloc)
<!-- * `open` (man 2 open) -->
* `opendir` (man 3 opendir)
<!-- * `perror` (man 3 perror) -->
<!-- * `read` (man 2 read) -->
* `readdir` (man 3 readdir)
<!-- * `signal` (man 2 signal) -->
* `_strdup` (man 3 strdup)
* `stat` (__xstat) (man 2 stat)
<!-- * `lstat` (__lxstat) (man 2 lstat) -->
<!-- * `fstat` (__fxstat) (man 2 fstat) -->
* `strtok` (man 3 strtok)
* `_strcmp` (man 3 strcmp)
* `wait` (man 2 wait)
<!-- * `waitpid` (man 2 waitpid) -->
<!-- * `wait3` (man 2 wait3) -->
<!-- * `wait4` (man 2 wait4) -->
<!-- * `write` (man 2 write) -->

## Compilation

Your shell will be compiled this way:
```hsh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh
```

## Testing

Your shell should work like this in interactive mode:
```hsh
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```hsh
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

Or also test to realize an analysis with valgrind tool
```
valgrind ./hsh
```

## man_1_simple_shell

Man page for the Simple man_1_simple_shell

To access manpage format:
```
man ./man_1_simple_shell
```

## Flowchart
![flowchart](https://github.com/CarolDianeHA/holbertonschool-simple_shell/blob/caroldiane/Images/Simple%20Shell%20Diagram.jpg)
## Authors

Carol Diane Hernandez [CarolDianeHA](https://github.com/CarolDianeHA)

Jose Acevedo [josemls](https://github.com/josemls)