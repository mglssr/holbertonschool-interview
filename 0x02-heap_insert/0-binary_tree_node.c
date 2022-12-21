#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_node -  function that creates a binary tree node
*@parent: is a pointer to the parent node of the node to create
*@value: is the value to put in the new node
*Return: return a pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
    if (!node)
		return (0);
	(*node).parent = parent;
	(*node).n = value;
	(*node).left = NULL;
	(*node).right = NULL;

	return (node);
}
