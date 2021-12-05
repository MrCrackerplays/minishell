/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dictionary.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:14:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:14:00 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dict	*ft_dict_new(char *key, void *value)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->tree = ft_tree_new(ft_dict_hash(key), value);
	return (dict);
}

void	ft_dict_add(t_dict *dict, char *key, void *value)
{
	ft_tree_add(&(dict->tree), ft_dict_hash(key), value);
}

void	*ft_dict_get(t_dict *dict, char *key)
{
	return (ft_tree_get(dict->tree, ft_dict_hash(key)));
}

void	ft_dict_free(t_dict *dict, void (*del)(void *))
{
	ft_tree_free(dict->tree, del);
	free(dict);
}

void	ft_dict_print_keys(t_tree *node)
{
	ft_dict_hash_print(node->key);
	ft_print(",", NULL);
	if (node->bigger)
		ft_dict_print_keys(node->bigger);
	if (node->smaller)
		ft_dict_print_keys(node->smaller);
}
