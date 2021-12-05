/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_a.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 13:42:47 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 14:59:43 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_a(char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		if (ft_isprint(s[i]))
			ft_putchar_fd(s[i], 1);
		else
		{
			ft_putstr_fd("(", 1);
			ft_putnbr_fd(s[i], 1);
			ft_putstr_fd(")", 1);
		}
		i++;
	}
	return (i);
}
