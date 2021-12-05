/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_find.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:54:27 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 19:38:17 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_str.h"

t_strlist	*ft_strlst_last(t_strlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_strlist	*ft_strlst_find(t_strlist *lst, t_string *text)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->str == text)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_strlst_find_indx(t_strlist *lst, t_string *text)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->str == text)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
