#include "binary_trees.h"

/**
 * height_b - Helper to measure the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t height_b(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + height_b(tree->left) : 0;
	r = tree->right ? 1 + height_b(tree->right) : 0;
	return (l >= r ? l : r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor. If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((int)height_b(tree->left) - (int)height_b(tree->right));
}
