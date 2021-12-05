/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_s.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 13:42:47 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 15:14:39 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_s(char *s)
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
		if (ft_isprint(s[i]) || s[i] == '\n' || s[i] == 9)
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
