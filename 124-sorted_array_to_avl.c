#include "binary_trees.h"

/**
 * _sorted_array_to_avl - Helper function for converting a sorted array to an AVL tree.
 * @array: Input array.
 * @start: Starting index.
 * @end: Ending index.
 * @parent: Pointer to the parent node.
 * Return: Newly created node.
 */
avl_t *_sorted_array_to_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *new;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	new = calloc(1, sizeof(avl_t));
	if (!new)
		return (NULL);
	new->n = array[mid];
	new->parent = parent;
	new->left = _sorted_array_to_avl(array, start, mid - 1, new);
	new->right = _sorted_array_to_avl(array, mid + 1, end, new);
	return (new);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Input array.
 * @size: Size of the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (_sorted_array_to_avl(array, 0, size - 1, NULL));
}
