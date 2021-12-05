/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_list_info.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:53:56 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/05 13:17:02 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_str.h"

void	ft_strlst_print(t_strlist *lst)
{
	ft_putchar_fd('{', 1);
	while (lst)
	{
		if (lst->str)
			ft_putstr_fd(lst->str->text, 1);
		else
			ft_putstr_fd("(null)", 1);
		if (lst->next)
			ft_putchar_fd(',', 1);
		lst = lst->next;
	}
	ft_putchar_fd('}', 1);
	ft_putchar_fd('\n', 1);
}

void	ft_strlst_print_c(t_strlist *lst, char c)
{
	ft_putchar_fd('{', 1);
	while (lst)
	{
		if (lst->str)
			ft_putstr_fd(lst->str->text, 1);
		else
			ft_putstr_fd("(null)", 1);
		if (lst->next)
			ft_putchar_fd(c, 1);
		lst = lst->next;
	}
	ft_putchar_fd('}', 1);
	ft_putchar_fd('\n', 1);
}

void	ft_strlst_print_s(t_strlist *lst, char *s)
{
	ft_putchar_fd('{', 1);
	while (lst)
	{
		if (lst->str)
			ft_putstr_fd(lst->str->text, 1);
		else
			ft_putstr_fd("(null)", 1);
		if (lst->next)
			ft_putstr_fd(s, 1);
		lst = lst->next;
	}
	ft_putchar_fd('}', 1);
	ft_putchar_fd('\n', 1);
}

int	ft_strlst_size(t_strlist *lst)
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
