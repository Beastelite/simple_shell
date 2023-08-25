#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, l;
	char *s = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
	l = k;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (s);
}

/**
 **_strncat - ctrings
 *@dest: thrst sing
 *@src: thecond stng
 *@n: the amobytes to baximally used
 *Return: thencatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int j, y;
	char *s = dest;

	j = 0;
	y = 0;
	while (dest[j] != '\0')
		j++;
	while (src[y] != '\0' && y < n)
	{
		dest[j] = src[y];
		j++;
		y++;
	}
	if (y < n)
		dest[j] = '\0';
	return (s);
}

/**
 **_strchr - lotes a charng
 *@s: thearsed
 *@c: thor tunder of for
 *Return: (s) a poinlets go yememory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

