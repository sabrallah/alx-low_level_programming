#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog struct
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: pointer to new dog struct
 **/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int name_len, owner_len;

	/* Allocate memory for new dog */
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	/* Copy name to new memory location */
	for (name_len = 0; name[name_len] != '\0'; name_len++)
	;
	new_dog->name = malloc(sizeof(char) * (name_len + 1));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	for (name_len = 0; name[name_len] != '\0'; name_len++)
	new_dog->name[name_len] = name[name_len];
	new_dog->name[name_len] = '\0';

	/* Copy owner to new memory location */
	for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
	;
	new_dog->owner = malloc(sizeof(char) * (owner_len + 1));
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}
	for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
	new_dog->owner[owner_len] = owner[owner_len];
	new_dog->owner[owner_len] = '\0';

	/* Set age */
	new_dog->age = age;

	return (new_dog);
}
