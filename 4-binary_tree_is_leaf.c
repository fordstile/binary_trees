#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to be checked.
 *
 * Return: If the node is a leaf - 1.
 *         Otherwise - 0.
 *
 * Description: This function checks if the given node is a leaf node in the
 *              binary tree. A leaf node is a node with no children (left or right).
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node == NULL || node->left != NULL || node->right != NULL)
        return (0);

    return (1);
}
