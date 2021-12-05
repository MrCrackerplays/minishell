/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_list_manage.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 17:28:45 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 18:12:05 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"

void	ft_intlst_add_back(t_intlist **lst, t_intlist *new)
{
	t_intlist	*end;

	if (*lst)
	{
		end = ft_intlst_last(*lst);
		end->next = new;
	}
	else
		*lst = new;
}

void	ft_intlst_add_front(t_intlist **lst, t_intlist *new)
{
	t_intlist	*tmp;

	tmp = &**lst;
	new->next = tmp;
	*lst = new;
}

void	ft_intlst_remove(t_intlist **lst, t_intlist *element)
{
	t_intlist	*indx;

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
