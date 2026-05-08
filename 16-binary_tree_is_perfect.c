#include "binary_trees.h"

static size_t tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree_height(tree->left);
	r = tree_height(tree->right);
	return (1 + (l >= r ? l : r));
}

static int check_perfect(const binary_tree_t *tree, size_t h, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (h == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_perfect(tree->left, h, level + 1) &&
		check_perfect(tree->right, h, level + 1));
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_perfect(tree, tree_height(tree), 0));
}
