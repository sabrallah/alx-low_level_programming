#include "main.h"
/**
 * _strstr - finds the first occurrence of the substring needle in haystack
 * @haystack: string to search in
 * @needle: substring to search for
 *
 * Return: pointer to the beginning of the located substring,
 * or 0 if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (!*needle)
		return (haystack);

	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j]; j++)
		{
			if (needle[j] != haystack[i + j])
				break;
		}
		if (!needle[j])
			return (haystack + i);
	}

	return (0);
}
