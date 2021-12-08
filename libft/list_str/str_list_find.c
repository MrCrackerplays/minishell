/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_list_find.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:54:27 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 18:40:20 by rdrazsky      ########   odam.nl         */
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

t_strlist	*ft_strlst_find(t_strlist *lst, char *text)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (ft_strncmp(lst->str->text, text, lst->str->len + 1) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_strlst_find_indx(t_strlist *lst, char *text)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (ft_strncmp(lst->str->text, text, lst->str->len + 1) == 0)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
