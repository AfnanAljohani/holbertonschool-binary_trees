#include "binary_trees.h"

/**
 * tree_size_c - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Size of the tree
 */
size_t tree_size_c(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_size_c(tree->left) + tree_size_c(tree->right));
}

/**
 * is_complete_helper - Recursive helper to check if tree is complete
 * @tree: Pointer to the current node
 * @index: Index of the current node
 * @size: Total size of the tree
 *
 * Return: 1 if complete, otherwise 0
 */
int is_complete_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete_helper(tree->left, 2 * index + 1, size) &&
		is_complete_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if complete, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = tree_size_c(tree);
	return (is_complete_helper(tree, 0, size));
}
