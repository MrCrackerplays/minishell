/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:59:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 19:38:17 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_str.h"

void	ft_strlst_iter(t_strlist *lst, void (*f)(t_string *))
{
	if (!lst || !f)
		return ;
	(*f)(lst->str);
	if (lst->next)
		ft_strlst_iter(lst->next, f);
}
