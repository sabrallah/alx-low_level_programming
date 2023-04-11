#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated space in memory containing
 * concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	int s1_len = 0, s2_len = 0;
	int i;

	if (s1 != NULL)
		while (s1[s1_len])
			s1_len++;
	if (s2 != NULL)
		while (s2[s2_len])
			s2_len++;
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	for (i = 0; i < s1_len; i++)
		result[i] = s1[i];
	for (i = 0; i < s2_len; i++)
		result[s1_len + i] = s2[i];
	result[s1_len + s2_len] = '\0';
	return (result);
}
