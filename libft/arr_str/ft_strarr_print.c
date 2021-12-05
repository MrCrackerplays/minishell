/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarr_print.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:46:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/05 13:21:43 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "arr_str.h"

void	ft_strarr_print(char **arr)
{
	size_t	i;

	i = 0;
	ft_putchar_fd('{', 1);
	while (arr[i])
	{
		if (arr[i])
			ft_putstr_fd(arr[i], 1);
		else
			ft_putstr_fd("(null)", 1);
		if (arr[i + 1])
			ft_putchar_fd(',', 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}

void	ft_strarr_print_c(char **arr, char c)
{
	size_t	i;

	i = 0;
	ft_putchar_fd('{', 1);
	while (arr[i])
	{
		if (arr[i])
			ft_putstr_fd(arr[i], 1);
		else
			ft_putstr_fd("(null)", 1);
		if (arr[i + 1])
			ft_putchar_fd(c, 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}

void	ft_strarr_print_s(char **arr, char *s)
{
	size_t	i;

	i = 0;
	ft_putchar_fd('{', 1);
	while (arr[i])
	{
		if (arr[i])
			ft_putstr_fd(arr[i], 1);
		else
			ft_putstr_fd("(null)", 1);
		if (arr[i + 1])
			ft_putstr_fd(s, 1);
		i++;
	}
	ft_putchar_fd('}', 1);
}
