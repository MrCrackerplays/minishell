/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 17:04:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/16 16:49:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lst_new(void *content);
void		ft_lst_add_front(t_list **lst, t_list *new);
int			ft_lst_size(t_list *lst);
t_list		*ft_lst_last(t_list *lst);
void		ft_lst_add_back(t_list **lst, t_list *new);
void		ft_lst_delone(t_list *lst, void (*del)(void *));
void		ft_lst_clear(t_list **lst, void (*del)(void *));
void		ft_lst_free(t_list *lst, void (*del)(void *));
void		ft_lst_iter(t_list *lst, void (*f)(void *));
t_list		*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		ft_lst_remove(t_list **lst, t_list *element);

#endif
