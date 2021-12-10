/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:52:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:39:16 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Get list element
t_list	*ft_lst_new(void *content)
{
	struct s_list	*list;

	list = (t_list *) ft_malloc_e(sizeof(t_list), "libft");
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lst_free(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (lst->next)
		ft_lst_free(lst->next, del);
	if (del)
		(*del)(lst->content);
	free(lst);
}

void	ft_lst_delone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

static void	del_list(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		del_list(lst->next, del);
	ft_lst_delone(lst, del);
}

void	ft_lst_clear(t_list **lst, void (*del)(void *))
{
	del_list(*lst, del);
	*lst = NULL;
}
