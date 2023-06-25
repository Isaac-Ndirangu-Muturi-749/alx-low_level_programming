#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: The operator passed as an argument
 *
 * Return: Pointer to the function that corresponds to the operator
 */
int (*get_op_func(char *s))(int, int)
{
	/* Declare and initialize an array of op_t structures */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int i = 0;

	/* Iterate over the ops array */
	while (ops[i].op != NULL)
	{
		/* Check if the current operator matches the argument */
		if (*(ops[i].op) == *s && *(s + 1) == '\0')
			return (ops[i].f);
		i++;
	}

	/* If no matching operator is found, return NULL */
	return (NULL);
}
