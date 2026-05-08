#include "binary_trees.h"

/**
 * height_p - Helper to measure the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t height_p(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + height_p(tree->left) : 0;
	r = tree->right ? 1 + height_p(tree->right) : 0;
	return (l >= r ? l : r);
}

/**
 * size_p - Helper to measure the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Size of the tree
 */
size_t size_p(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + size_p(tree->left) + size_p(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h, s, expected;

	if (tree == NULL)
		return (0);
	h = height_p(tree);
	s = size_p(tree);
	expected = (1 << (h + 1)) - 1;
	return (s == expected);
}
