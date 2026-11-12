#include "main.h"

/**
 * _strncpy - copies a string, using at most n bytes from src
 * @dest: the destination buffer
 * @src: the source string
 * @n: the number of bytes to fill in dest
 *
 * Return: a pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
