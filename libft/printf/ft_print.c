/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 16:08:50 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:39:50 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

static int	f_fork(char c, void *item)
{
	if (c == 's')
		return (ft_s((char *) item));
	else if (c == 'i' || c == 'd')
		return (ft_i((long) item));
	else if (c == 'a')
		return (ft_a((char *) item));
	else if (c == 'l')
		return (ft_l((long) item));
	else if (c == 'b')
		return (ft_b((int) item));
	else if (c == 'x')
		return (ft_x((unsigned int) item));
	else if (c == 'c')
		return (ft_c((int) item));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

static int	ft_printf_parse(const char *s, void *item)
{
	int		chr_cnt;
	int		mid_bs;

	chr_cnt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			mid_bs = f_fork(*(s + 1), item);
			if (mid_bs != -1)
			{
				s++;
				chr_cnt += mid_bs;
			}
		}
		else
		{
			ft_putchar_fd(*s, 1);
			chr_cnt++;
		}
		s++;
	}
	return (chr_cnt);
}

int	ft_print(const char *s, void *item)
{
	int		chr_cnt;

	chr_cnt = 0;
	if (s)
		chr_cnt = ft_printf_parse(s, item);
	return (chr_cnt);
}
