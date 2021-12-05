/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_list_info.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 17:29:42 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 19:16:10 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"
#include "../libft.h"

void	ft_intlst_print(t_intlist *lst)
{
	ft_putchar_fd('{', 1);
	while (lst)
	{
		ft_putnbr_fd(lst->value, 1);
		if (lst->next)
			ft_putchar_fd(',', 1);
		lst = lst->next;
	}
	ft_putchar_fd('}', 1);
	ft_putchar_fd('\n', 1);
}

int	ft_intlst_size(t_intlist *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

BOOL	ft_intlst_is_sorted(t_intlist *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		if (lst->next->value < lst->value)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}
