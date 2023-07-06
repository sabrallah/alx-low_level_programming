#include "hash_tables.h"

/**
 * key_index - Returns the index of a key in the hash table.
 * @key: The key to find the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	/* Use the djb2 hashing algorithm to calculate the hash value */
	unsigned long int hash_value = hash_djb2(key);

/* Calculate index in the array by taking modulo of hash value with array */
	index = hash_value % size;

	return (index);
}
