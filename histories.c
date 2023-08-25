#include "shell.h"
/**
 * get_history_file - gets the history
 * @info: struct
 * Return: string with history
 */
char *get_history_file(info_t *info)
{
	char *buffer, *directory;

	directory = _getenv(info, "HOME=");
	if (!directory)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(directory) + _strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, directory);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}
/**
 * write_history - creates or appends
 * @info: the struct
 * Return: 1 on success, else -1 on failure
 */
int write_history(info_t *info)
{
	ssize_t file_descriptor;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (file_descriptor == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, file_descriptor);
		_putfd('\n', file_descriptor);
	}
	_putfd(BUF_FLUSH, file_descriptor);
	close(file_descriptor);
	return (1);
}
/**
 * read_history - reads history
 * @info: the struct
 * Return: history count
 */
int read_history(info_t *info)
{
	int x, last = 0, count = 0;
	ssize_t fd, rdlen, size = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		size = st.st_size;
	if (size < 2)
		return (0);
	buf = malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, size);
	buf[size] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (x = 0; x < size; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, count++);
			last = x + 1;
		}
	if (last != x)
		build_history_list(info, buf + last, count++);
	free(buf);
	info->histcount = count;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list - history linked list
 * @info: Structure arguments
 * @buf: buffer
 * @linecount: the history linecount
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *nodes = NULL;

	if (info->history)
		nodes = info->history;
	add_node_end(&nodes, buf, linecount);
	if (!info->history)
		info->history = nodes;
	return (0);
}
/**
 * renumber_history - renumbers the history linked list
 * @info: Structure arguments
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
