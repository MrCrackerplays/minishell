/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarr_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/05 15:52:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/07 12:33:42 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "arr_str.h"

void	ft_strarr_free(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free1(arr[i]);
		i++;
	}
	free(arr);
}
