/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_list_mem.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 15:46:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:39:32 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"
#include "../libft.h"

t_intlist	*ft_intlst_new(int value)
{
	struct s_intlist	*list;

	list = (t_intlist *) ft_malloc_e(sizeof(t_intlist), "libft");
	list->value = value;
	list->next = NULL;
	return (list);
}

t_intlist	*ft_intlst_copy(t_intlist *og_lst)
{
	t_intlist	*lst;
	t_intlist	*lst_indx;

	if (!og_lst)
		return (NULL);
	lst = ft_intlst_new(og_lst->value);
	lst_indx = lst;
	og_lst = og_lst->next;
	while (og_lst)
	{
		lst_indx->next = ft_intlst_new(og_lst->value);
		if (!lst_indx->next)
		{
			ft_intlst_free(lst);
			return (NULL);
		}
		lst_indx = lst_indx->next;
		og_lst = og_lst->next;
	}
	return (lst);
}

void	ft_intlst_free(t_intlist *lst)
{
	if (!lst)
		return ;
	if (lst->next)
	{
		ft_intlst_free(lst->next);
		lst->next = NULL;
	}
	lst->value = 0;
	free(lst);
}

t_intlist	*ft_intlst_arg2list(int argc, char **argv)
{
	t_intlist	*lst;
	t_intlist	*tmp;
	int			i;

	lst = NULL;
	i = 0;
	while (i < argc)
	{
		tmp = ft_intlst_new(ft_latoi(argv[i]));
		if (!tmp)
		{
			ft_intlst_free(lst);
			return (NULL);
		}
		ft_intlst_add_back(&lst, tmp);
		i++;
	}
	return (lst);
}
