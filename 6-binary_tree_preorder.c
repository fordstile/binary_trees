#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree to be traversed.
 * @func: A pointer to a function to be called for each node.
 *
 * Description: This function traverses the binary tree rooted at 'tree' using
 *              pre-order traversal and calls the function pointed to by 'func'
 *              for each visited node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        func(tree->n);
        binary_tree_preorder(tree->left, func);
        binary_tree_preorder(tree->right, func);
    }
}
