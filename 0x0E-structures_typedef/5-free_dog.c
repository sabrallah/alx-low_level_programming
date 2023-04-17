#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees a dog struct
 * @d: pointer to dog struct
 *
 * Return: void
 **/
void free_dog(dog_t *d)
{
	/* Check if pointer is NULL */
	if (d == NULL)
		return;

	/* Free name and owner memory */
	free(d->name);
	free(d->owner);

	/* Free struct memory */
	free(d);
}
