/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterable.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:14:10 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:14:10 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_N_DICT_H
# define TREE_N_DICT_H

# include <stdlib.h>
# include <string.h>

// -~{ TREE }~- //

typedef struct s_tree_node
{
	int64_t				key;
	void				*value;
	struct s_tree_node	*bigger;
	struct s_tree_node	*smaller;
}	t_tree;

t_tree			*ft_tree_new(int key, void *value);
void			ft_tree_add(t_tree **node, int key, void *item);
void			*ft_tree_get(t_tree *node, int key);
void			ft_tree_free(t_tree *node, void (*del)(void *));
void			ft_tree_print_keys(t_tree *node);

// -~{ DICTIONARY }~- //

typedef struct s_dictionary
{
	t_tree	*tree;
}	t_dict;

unsigned long	ft_dict_hash(char *str);
void			ft_dict_hash_print(unsigned long key);

t_dict			*ft_dict_new(char *key, void *value);
void			ft_dict_add(t_dict *dict, char *key, void *item);
void			*ft_dict_get(t_dict *dict, char *key);
void			ft_dict_free(t_dict *dict, void (*del)(void *));
void			ft_dict_print_keys(t_tree *node);

#endif
