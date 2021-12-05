/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_manage.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:54:59 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/21 16:47:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (*lst)
	{
		end = ft_lst_last(*lst);
		end->next = new;
	}
	else
		*lst = new;
}

void	ft_lst_add_front(t_list **lst, t_list *new)
{
	t_list	*o_item;

	o_item = &**lst;
	new->next = o_item;
	*lst = new;
}

void	ft_lst_remove(t_list **lst, t_list *element)
{
	t_list	*indx;

	if (!*lst)
		return ;
	if (*lst == element)
	{
		indx = *lst;
		*lst = indx->next;
		indx->next = NULL;
		return ;
	}
	indx = (*lst);
	while (indx->next)
	{
		if (indx->next == element)
		{
			indx->next = indx->next->next;
			element->next = NULL;
			return ;
		}
		indx = indx->next;
	}
}
