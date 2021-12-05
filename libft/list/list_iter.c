/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:59:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 14:33:20 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//	Apply function to each element in list
void	ft_lst_iter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	(*f)(lst->content);
	if (lst->next)
		ft_lst_iter(lst->next, f);
}
