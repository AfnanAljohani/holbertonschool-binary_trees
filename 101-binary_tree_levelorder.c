#include "binary_trees.h"

/**
 * tree_height_l - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
size_t tree_height_l(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + tree_height_l(tree->left) : 0;
	r = tree->right ? 1 + tree_height_l(tree->right) : 0;
	return (l >= r ? l : r);
}

/**
 * print_level - Prints all nodes at a given level
 * @tree: Pointer to the root node
 * @level: Level to print
 * @func: Pointer to a function to call for each node
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing. If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = tree_height_l(tree);
	for (i = 0; i <= height; i++)
		print_level(tree, i, func);
}
