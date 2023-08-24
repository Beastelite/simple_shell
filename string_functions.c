#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory, of
 * a copy of the string passed
 * @str: pointer to a string
 * Return: pointer to the new string
 */
char *_strdup(char *str)
{
	int i, l;
	char *dup_str;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	dup_str = malloc(sizeof(char) * l + 1);
	if (!dup_str)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		dup_str[i] = str[i];
	}
	dup_str[l] = str[l];
	return (dup_str);
}

/**
 * _concat - concats 3 strings in a newly allocated memory
 * @str1: first string
 * @str2: second string
 * @str3 Third string
 * Return: pointer to the new string
 */
char *_concat(char *str1, char *str2, char *str3)
{
	char *concat_str;
	int len1, len2, len3, i, j;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len3 = _strlen(str3);

	concat_str = malloc(len1 + len2 + len3 + 1);
	if (!concat_str)
		return (NULL);

	for (i = 0; str1[i]; i++)
		concat_str[i] = str1[i];
	j = i;

	for (i = 0; str2[i]; i++)
		concat_str[j + i] = str2[i];
	j = j + i;

	for (i = 0; str3[i]; i++)
		concat_str[j + i] = str3[i];
	j = j + i;

	result[j] = '\0';

	return (concat_str);
}

/**
 * _strlen - it gives the length of a string
 * @str: pointer to the string
 * Return: the length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar – prints a character to stdout
 * @c: character to print
 *
 * Return: 1 on success
 * On error, -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: strings’ pointer
 */

void _puts(char *str)
{
	int i;

	for(i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
}

