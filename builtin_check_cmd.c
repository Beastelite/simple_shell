#include "shell.h"

/**
* buildccheck - checks if the command is a builtin functions
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*buildcheck(char **arv))(char **arv)
{
	int i, j;
	builtin T[] = {
		{"exit", _exit},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}

