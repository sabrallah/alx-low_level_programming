#ifndef DOG_H
#define DOG_H

/**
 * struct dog - information about a dog
 *
 * @name: name of the dog (string)
 * @age: age of the dog (float)
 * @owner: name of the dog's owner (string)
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

#endif
