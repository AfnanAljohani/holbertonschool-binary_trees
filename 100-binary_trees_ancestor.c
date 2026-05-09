#include "binary_trees.h"

/**
 * depth_a - Measures the depth of a node
 * @tree: Pointer to the node
 *
 * Return: Depth of the node
 */
size_t depth_a(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	return (1 + depth_a(tree->parent));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d1, d2;

	if (first == NULL || second == NULL)
		return (NULL);

	d1 = depth_a(first);
	d2 = depth_a(second);

	while (d1 > d2)
	{
		first = first->parent;
		d1--;
	}
	while (d2 > d1)
	{
		second = second->parent;
		d2--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
