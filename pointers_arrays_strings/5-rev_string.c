#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0;
	int len = 0;
	char tmp;

	while (s[len] != '\0')
		len++;

	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
}
