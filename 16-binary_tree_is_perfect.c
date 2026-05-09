#include "binary_trees.h"

/**
 * binary_tree_height_perf - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t binary_tree_height_perf(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + binary_tree_height_perf(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height_perf(tree->right) : 0;
	return (l > r ? l : r);
}

/**
 * is_perfect_recursive - Recursive helper to check if tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected depth of leaves
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	depth = binary_tree_height_perf(tree);
	return (is_perfect_recursive(tree, depth, 0));
}
