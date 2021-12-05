/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 16:08:50 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:40:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft.h"
#include "printf.h"

static int	f_fork(char c, va_list args)
{
	if (c == 's')
		return (ft_s(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_i(va_arg(args, int)));
	else if (c == 'a')
		return (ft_a(va_arg(args, char *)));
	else if (c == 'l')
		return (ft_l(va_arg(args, long)));
	else if (c == 'b')
		return (ft_b(va_arg(args, int)));
	else if (c == 'x')
		return (ft_x(va_arg(args, unsigned int)));
	else if (c == 'c')
		return (ft_c(va_arg(args, int)));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (2 + ft_p(va_arg(args, unsigned long)));
	}
	return (-1);
}

static int	ft_printf_parse(const char *s, va_list args)
{
	int		chr_cnt;
	int		mid_bs;

	chr_cnt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			mid_bs = f_fork(*(s + 1), args);
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

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		chr_cnt;

	chr_cnt = 0;
	va_start(args, s);
	if (s)
		chr_cnt = ft_printf_parse(s, args);
	va_end(args);
	return (chr_cnt);
}
