#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL; /* Pointer to the root node of the AVL tree */
	size_t i, j; /* Loop counters */

	/* Check if the input array is NULL */
	if (array == NULL)
		return (NULL);

	/* Iterate through the array */
	for (i = 0; i < size; i++)
	{
		/* Check if the current value is a duplicate */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		/* If no duplicate is found, insert the value into the AVL tree */
		if (j == i)
		{
			/* Insert the value into the AVL tree */
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL); /* Return NULL on insertion failure */
		}
	}

	/* Return a pointer to the root node of the created AVL tree */
	return (tree);
}

