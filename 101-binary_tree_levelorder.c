#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree. If 'tree' is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left, right;

    if (tree == NULL)
        return (0);
    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);
    if (left >= right)
        return (1 + left);
    return (1 + right);
}

/**
 * binary_tree_level - Performs a function on a specific level of a binary tree.
 * @tree: Pointer to the root of the tree.
 * @l: Level of the tree to perform a function on.
 * @func: Function to perform.
 *
 * Return: Void
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
    if (tree == NULL)
        return;
    if (l == 1)
        func(tree->n);
    else if (l > 1)
    {
        binary_tree_level(tree->left, l - 1, func);
        binary_tree_level(tree->right, l - 1, func);
    }
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function.
 *
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, i;

    if (tree == NULL || func == NULL)
        return;
    height = binary_tree_height(tree);
    for (i = 1; i <= height; i++)
        binary_tree_level(tree, i, func);
}
