/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_list_find.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 16:46:13 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 17:21:24 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"

t_intlist	*ft_intlst_find(t_intlist *lst, int value)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->value == value)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_intlst_find_indx(t_intlist *lst, int value)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->value == value)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

t_intlist	*ft_intlst_last(t_intlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_intlist	*ft_intlst_find_max(t_intlist *lst)
{
	t_intlist	*max;

	if (!lst)
		return (NULL);
	max = lst;
	while (lst)
	{
		if (max->value < lst->value)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_intlist	*ft_intlst_find_min(t_intlist *lst)
{
	t_intlist	*min;

	if (!lst)
		return (NULL);
	min = lst;
	while (lst)
	{
		if (min->value > lst->value)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
