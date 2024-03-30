#include "binary_trees.h"
#include "limits.h"

/* Function prototypes */
size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t height(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        size_t left_height = 0, right_height = 0;

        left_height = tree->left ? 1 + height(tree->left) : 1;
        right_height = tree->right ? 1 + height(tree->right) : 1;
        return (left_height > right_height ? left_height : right_height);
    }
    return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid AVL tree, return 1, otherwise, return 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
    size_t left_height, right_height, height_diff;

    if (tree != NULL)
    {
        if (tree->n < lo || tree->n > hi)
            return (0);

        left_height = height(tree->left);
        right_height = height(tree->right);

        height_diff = left_height > right_height ? left_height - right_height : right_height - left_height;
        if (height_diff > 1)
            return (0);

        return (is_avl_helper(tree->left, lo, tree->n - 1) && is_avl_helper(tree->right, tree->n + 1, hi));
    }
    return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

