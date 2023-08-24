#include "shell.h"

/**
 * sig_handler - checks if Ctrl C character is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n#myShell$ ");
	}
}

/**
* _EOF - checks the End of File
* @len: return value of the getline function
* @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty – check if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#myShell$ ");
}
/**
 * main – my simple shell
 * Return: On success, 1
 */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = _splitstring(buff, " \n");
		if (!arv || !arv[0])
			run_cmd(arv);
		else
		{
			value = _getenv("PATH");
			head = link_path(value);
			pathname = get_cmd_location(arv[0], head);
			f = buildcheck(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				run_cmd(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				run_cmd(arv);
			}
		}
	}
	_freelist(head);
	free_aargs(arv);
	free(buff);
	return (0);
}

