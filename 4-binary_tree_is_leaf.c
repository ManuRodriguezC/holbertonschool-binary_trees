#include "binary_trees.h"

/**
* binary_tree_is_leaf - function that checks if a node is a leaf
* @node: is a pointer to the node to check
* Return: 1 or 0 if node is NULL
**/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left || node->right || node == NULL)
		return (0);
	else
		return (1);
}