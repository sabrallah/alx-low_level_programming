#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the array
 * Return: Pointer to the newly created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = calloc(1, sizeof(shash_table_t));

	if (!ht)
		return (NULL);
	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}
	return (ht);
}

/**
 * shash_table_set - Add or update key/value pair to the sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key (string)
 * @value: The value corresponding to the key
 * Return: 1 if success, 0 if failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp;
	unsigned long int index;

	if (!ht || !key || !strlen(key) || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (!strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (tmp->value ? 1 : 0);
		}
		tmp = tmp->next;
	}
	new_node = calloc(1, sizeof(shash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (!new_node->key || !new_node->value)
	{
		if (new_node->key)
			free(new_node->key);
		if (new_node->value)
			free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		return (1);
	}
	if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext && strcmp(new_node->key, tmp->snext->key) > 0)
			tmp = tmp->snext;
		new_node->sprev = tmp;
		new_node->snext = tmp->snext;
		if (tmp->snext)
			tmp->snext->sprev = new_node;
		else
			ht->stail = new_node;
		tmp->snext = new_node;
	}
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: Pointer to the sorted hash table
 * @key: The key (string)
 * Return: The value associated with the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key || !strlen(key))
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (!strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht)
		return;

	printf("{");
	tmp = ht->shead;
	while (tmp)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (tmp->snext)
			printf(", ");
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse order
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht)
		return;

	printf("{");
	tmp = ht->stail;
	while (tmp)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (tmp->sprev)
			printf(", ");
		tmp = tmp->sprev;
	}
	printf("}\n");
}
