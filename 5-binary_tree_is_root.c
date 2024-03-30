#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root of a binary tree.
 * @node: A pointer to the node to be checked.
 *
 * Return: If the node is a root - 1.
 *         Otherwise - 0.
 *
 * Description: This function checks if the given node is the root of the
 *              binary tree. A root node is a node with no parent.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL || node->parent != NULL)
        return (0);

    return (1);
}
