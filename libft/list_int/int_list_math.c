/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_list_math.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/05 17:24:14 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 18:12:29 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "int_list.h"

void	ft_intlst_add_all(t_intlist *lst, int value)
{
	while (lst)
	{
		lst->value += value;
		lst = lst->next;
	}
}

void	ft_intlst_mult_all(t_intlist *lst, int value)
{
	while (lst)
	{
		lst->value *= value;
		lst = lst->next;
	}
}

int	ft_intlst_sum(t_intlist *lst)
{
	int	sum;

	sum = 0;
	while (lst)
	{
		sum += lst->value;
		lst = lst->next;
	}
	return (sum);
}
