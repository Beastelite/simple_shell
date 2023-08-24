#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
/* string functions*/
int _strlen(char *s);
char *_strdup(char *str);
char *_concat(char *name, char *sep, char *value);

char **_splitstring(char *str, const char *delim);
void run_cmd(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_path - PATH directories
 * @directory: path directory
 * @p: next node
 */
typedef struct list_path
{
	char *directory;
	struct list_path *p;
} list_path;


char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *link_path(char *path);
char *get_cmd_location(char *filename, list_path *head);

/**
 * struct builtin - struct builtin
 * @name:  command
 * @func: execute the command
 */
typedef struct builtin
{
	char *name;
	void (*func)(char **);
} builtin;
/* string functions */
void(*buildcheck(char **arv))(char **arv);
int _atoi(char *s);
/* environ functions*/
void _exitt(char **arv);
void _env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);
/* free functions */
void free_aargs(char **arv);
void _freelist(list_path *head);


#endif

