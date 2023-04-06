#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to string to search
 * @c: character to search for
 *
 * Return: pointer to first occurrence of c in s, or 0 if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (0);
}
