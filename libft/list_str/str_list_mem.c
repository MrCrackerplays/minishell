/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_list_mem.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:52:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:39:42 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_str.h"

t_strlist	*ft_strlst_new(t_string *text)
{
	t_strlist	*lst;

	lst = (t_strlist *) ft_malloc_e(sizeof(t_strlist), "libft");
	lst->str = text;
	lst->next = NULL;
	return (lst);
}

void	ft_strlst_free(t_strlist *lst)
{
	if (!lst)
		return ;
	if (lst->next)
	{
		ft_strlst_free(lst->next);
		lst->next = NULL;
	}
	ft_str_free(lst->str);
	free(lst);
}

t_strlist	*ft_strlst_copy(t_strlist *lst)
{
	t_strlist	*dlst;
	t_string	*tmp1;
	t_strlist	*tmp2;

	dlst = NULL;
	while (lst)
	{
		tmp1 = ft_str_copy(lst->str);
		if (!tmp1)
		{
			ft_strlst_free(dlst);
			return (NULL);
		}
		tmp2 = ft_strlst_new(tmp1);
		if (!tmp2)
		{
			ft_strlst_free(dlst);
			return (NULL);
		}
		ft_strlst_add_back(&dlst, tmp2);
		lst = lst->next;
	}
	return (dlst);
}
