/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarr_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/05 15:52:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/05 13:23:41 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "arr_str.h"

void	ft_strarr_free(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
