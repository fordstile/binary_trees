#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns the
 *         height of the tree.
 *
 * Description: This function measures the height of the binary tree rooted at
 *              the given node 'tree'. The height of a binary tree is defined
 *              as the length of the longest path from the root node to a leaf
 *              node. If the tree is empty (tree is NULL), the height is 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t l = 0, r = 0;

        l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        return ((l > r) ? l : r);
    }
    return (0);
}
