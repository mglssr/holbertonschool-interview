#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array.
 * @array: is a pointer to the first element of the array to be converted.
 * @size: is the number of element in the array.
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node = NULL;

	if (!array || !size)
		return (NULL);

	node = SortedArrayToAVL(array, 0, size - 1, NULL);
	return (node);
}

/**
 * *binary_tree_node - builds an AVL tree from an array
 * @parent: the array to be printed
 * @index: size of the array
 * @array: is a pointer to the first element of the array to be converted.
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *binary_tree_node(avl_t *parent, int index, int *array)
{
	avl_t *node = NULL;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->left = node->right = NULL;
	node->n = array[index];
	node->parent = parent;

	return (node);
}

/**
 * *SortedArrayToAVL - builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted.
 * @root: root
 * @start: start
 * @end: end
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *SortedArrayToAVL(int *array, size_t start, size_t end, avl_t *root)
{
	size_t mid;
	avl_t *node = NULL;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = binary_tree_node(root, mid, array);
	if (!node)
		return (NULL);

	if (mid != start)
		node->left = SortedArrayToAVL(array, start, mid - 1, node);

	if (mid != end)
		node->right = SortedArrayToAVL(array, mid + 1, end, node);

	return (node);
}
