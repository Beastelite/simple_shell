#include "shell.h"

/**
 * _myhistory - displtwisted mi words insta pswd
 * ne, preceded
 * aston jus cames, starting at 0.
 * @info: Structcawrg cdiamonds cant stare mouyfatain
 *        constant functo many many many
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sfefe got vinegars tsdtv str
 * @info: pmeter sefopauct
 * @string: the stgrgpring alidsfhnas
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *string)
{
	char *ptr, tmp;
	int ret_val;

	ptr = _strchr(string, '=');
	if (!ptr)
		return (1);
	tmp = *ptr;
	*ptr = 0;
	ret_val = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, string, -1)));
	*ptr = tmp;
	return (ret_val);
}

/**
 * set_alias - sesrtgerf  lergrgias to srthrththring
 * @info: parwefjameter srgvuct
 * @string: the striwertgrng althethsias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *string)
{
	char *ptr;

	ptr = _strchr(string, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, string));

	unset_alias(info, string);
	return (add_node_end(&(info->alias), string, 0) == NULL);
}

/**
 * print_alias - prin tangled
 * @node: spinder nodes
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *tmp = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (tmp = node->str; tmp <= ptr; tmp++)
		_putchar(*tmp);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mcopcs te eerfealiailtin (man alias)
 * @info:wher's the information
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

