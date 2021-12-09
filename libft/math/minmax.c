/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minmax.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 17:42:48 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/09 17:43:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
