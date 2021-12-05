/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_i.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 17:01:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:38:51 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_i(long n)
{
	int		len;

	n = (int)n;
	len = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		len++;
	}
	if (n > 9)
		len += ft_i(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (len);
}
