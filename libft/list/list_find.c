/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_find.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:54:27 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 18:24:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Get last element
t_list	*ft_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_find(t_list *lst, void *content)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->content == content)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_lst_find_indx(t_list *lst, void *content)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == content)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
