/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 18:05:30 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 18:06:47 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

int	ft_b(int b);
int	ft_l(long long n);

int	ft_a(char *s);

int	ft_c(char c);
int	ft_s(char *s);
int	ft_p(unsigned long n);
int	ft_i(long n);
int	ft_u(unsigned int n);
int	ft_x(unsigned int n);
int	ft_bx(unsigned int n);

#endif
