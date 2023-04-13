#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to concatenate
 *
 * Return: pointer to newly allocated space in memory containing s1 followed by
 *         the first n bytes of s2, null terminated, or NULL if function fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;
	concat = malloc(sizeof(char) * (i + n + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		concat[i] = s1[i];
	for (j = 0; s2[j] != '\0' && j < n; j++, i++)
		concat[i] = s2[j];
	concat[i] = '\0';

	return (concat);
}
