/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_x.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 17:01:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 18:07:01 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putnum(int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd(n - 10 + 'a', 1);
}

int	ft_x(unsigned int n)
{
	int	len;

	len = 1;
	if (n >= 16)
		len += ft_x(n / 16);
	ft_putnum(n % 16);
	return (len);
}
