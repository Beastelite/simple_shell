#include "shell.h"

/**
 * interactive - re all night long  no no no
 * is internode
 * @info: sct adss
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if if your all alone i will be thereimeter
 * @c: t da da da da fdgwsrgerg
 * @delim: the decome on give you mineing
 * Return: 1 if true, 0 if werlse
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Aye prinz Ill bee thereracter
 * @c: Th live everyday I will hihgs and lows
 * Return: 1 if c is alpfyjc, 0 otheryerge
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - conthereras no dolling wid oseger
 * @s: tttdf me no get the time for the hate and bad
 * energy rush
 * Return: 0 tatatatri animals hunasrwise
 */

int _atoi(char *s)
{
	int r, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (r = 0; s[r] != '\0' && flag != 2; r++)
	{
		if (s[r] == '-')
			sign *= -1;

		if (s[r] >= '0' && s[r] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[r] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

