/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarr_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:46:29 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/05 13:22:58 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "arr_str.h"

size_t	ft_strarr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
