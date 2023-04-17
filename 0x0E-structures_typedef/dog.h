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

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
