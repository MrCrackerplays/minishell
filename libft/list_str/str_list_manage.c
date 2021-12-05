/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_list_manage.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:54:59 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/21 17:03:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_str.h"

void	ft_strlst_add_back(t_strlist **lst, t_strlist *new)
{
	t_strlist	*end;

	if (*lst)
	{
		end = ft_strlst_last(*lst);
		end->next = new;
	}
	else
		*lst = new;
}

void	ft_strlst_add_front(t_strlist **lst, t_strlist *new)
{
	t_strlist	*o_item;

	o_item = &**lst;
	new->next = o_item;
	*lst = new;
}

void	ft_strlst_remove(t_strlist **lst, t_strlist *element)
{
	t_strlist	*indx;

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
