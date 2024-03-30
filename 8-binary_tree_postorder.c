#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to be traversed.
 * @func: A pointer to a function to be called for each node.
 *
 * Description: This function traverses the binary tree rooted at 'tree' using
 *              post-order traversal and calls the function pointed to by 'func'
 *              for each visited node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        binary_tree_postorder(tree->left, func);
        binary_tree_postorder(tree->right, func);
        func(tree->n);
    }
}
