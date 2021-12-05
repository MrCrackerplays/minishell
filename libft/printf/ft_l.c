/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_l.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 13:42:47 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 18:10:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_l(long long n)
{
	long		len;

	n = (long)n;
	len = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		len++;
	}
	if (n > 9)
		len += ft_l(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	return (len);
}
