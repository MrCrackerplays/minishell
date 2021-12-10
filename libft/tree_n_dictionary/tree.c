/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:13:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:13:46 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_tree	*ft_tree_new(int key, void *value)
{
	t_tree	*tree;

	tree = ft_malloc_e(sizeof(t_tree), "libft");
	tree->key = key;
	tree->value = value;
	tree->bigger = NULL;
	tree->smaller = NULL;
	return (tree);
}

void	ft_tree_add(t_tree **node, int key, void *value)
{
	if (!(*node))
		*node = ft_tree_new(key, value);
	else
	{
		if (key > (*node)->key)
			ft_tree_add(&(*node)->bigger, key, value);
		else if (key < (*node)->key)
			ft_tree_add(&(*node)->smaller, key, value);
	}
}

void	*ft_tree_get(t_tree *node, int key)
{
	if (key == node->key)
		return (node->value);
	if (node->bigger && key > node->key)
		return (ft_tree_get(node->bigger, key));
	if (node->smaller && key < node->key)
		return (ft_tree_get(node->smaller, key));
	return (NULL);
}

void	ft_tree_free(t_tree *node, void (*del)(void *))
{
	if (node->value && del)
		(*del)(node->value);
	if (node->bigger)
		ft_tree_free(node->bigger, del);
	if (node->smaller)
		ft_tree_free(node->smaller, del);
	free(node);
}

void	ft_tree_print_keys(t_tree *node)
{
	ft_printf("\"%l\"", node->key);
	if (node->bigger || node->smaller)
		ft_print(",", NULL);
	if (node->bigger)
		ft_tree_print_keys(node->bigger);
	if (node->smaller)
		ft_tree_print_keys(node->smaller);
}
