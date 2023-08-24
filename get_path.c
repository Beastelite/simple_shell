#include "shell.h"


/**
 * _getenv - gets the global variable
 * @name: name of global variable
 * Return: value
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}


/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

list_path *add_node_end(list_path **head, char *str)
{

	list_path *temp;
	list_path *new_node;

	new_node = malloc(sizeof(list_path));

	if (!new_node || !str)
	{
		return (NULL);
	}

	new_node->directory = str;

	new_node->p = '\0';
	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;

		while (temp->p)
		{

			temp = temp->p;
		}

		temp->p = new_node;
	}

	return (*head);
}


/**
 * link_path - creates list for path directories
 * @path: string of path value
 * Return: pointer to the list
 */
list_path *link_path(char *path)
{
	list_path *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * get_cmd_location - finds the pathname of a command
 * @filename: command
 * @head: head of the linked list of path directories
 * Return: pathname or NULL on failure
 */
char *get_cmd_location(char *filename, list_path *head)
{
	struct stat st;
	char *string;

	list_path *tmp = head;

	while (tmp)
	{

		string = _concat(tmp->directory, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * _freelist - frees a list_t
 *@head: pointer tothe linked list
 */
void _freelist(list_path *head)
{
	list_path *location;

	while (head)
	{
		location = head->p;
		free(head->directory);
		free(head);
		head = location;
	}

}

