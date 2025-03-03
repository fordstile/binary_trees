#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node != NULL && node->left == NULL && node->right == NULL)
        return (1);
    return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
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
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    binary_tree_t *l, *r;

    if (tree == NULL)
        return (0);
    l = tree->left;
    r = tree->right;
    if (binary_tree_is_leaf(tree))
        return (1);
    if (l == NULL || r == NULL)
        return (0);
    if (binary_tree_height(l) == binary_tree_height(r))
    {
        if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
            return (1);
    }
    return (0);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t l_height, r_height;
    binary_tree_t *l, *r;

    if (tree == NULL)
        return (0);
    if (binary_tree_is_leaf(tree))
        return (1);
    l = tree->left;
    r = tree->right;
    l_height = binary_tree_height(l);
    r_height = binary_tree_height(r);
    if (l_height == r_height)
    {
        if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
            return (1);
    }
    else if (l_height == r_height + 1)
    {
        if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
            return (1);
    }
    return (0);
}
