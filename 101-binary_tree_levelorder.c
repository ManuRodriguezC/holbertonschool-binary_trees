#include "binary_trees.h"

/**
 * binary_tree_height - Function that search to height of a binary tree
 * @tree: The structure a binary
 * Return: height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left < right)
		return (right + 1);
	else
		return (left + 1);
}

/**
 * current_level - Function that goes through a binary tree
 * @tree: Tree is a structure binary tree
 * @func: pointer to a function to call for each node
 * @level: Function is called each level in the tree
 */
void current_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		current_level(tree->left, func, level - 1);
		current_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Function that goes through a binary tree
 * using level-order traversal
 * @tree: Tree is a structure binary
 * @func: pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = binary_tree_height(tree), level = 1;

	if (tree == NULL || func == NULL)
		return;

	for (; level <= h; level++)
		current_level(tree, func, level);
}
