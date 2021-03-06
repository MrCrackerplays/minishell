/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:00:07 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 12:36:25 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Convert string to int
int	ft_atoi(const char *nptr)
{
	int	num;
	int	mul;

	num = 0;
	mul = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		mul = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num += *nptr - 48;
		nptr++;
	}
	return (num * mul);
}
