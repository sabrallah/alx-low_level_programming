#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: Operator passed as argument
 *
 * Return: A pointer to the function corresponding to the operator given
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL && (s[0] != ops[i].op[0] || s[1] != '\0'))
		i++;

	return (ops[i].f);
}
