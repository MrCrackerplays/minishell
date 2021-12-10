/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarr_copy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:44:42 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:36:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "arr_str.h"

char	**ft_strarr_copy(char **arr)
{
	char	**new_arr;
	int		i;

	new_arr = ft_malloc_e(sizeof(char *) * (ft_strarr_len(arr) + 1), "libft");
	i = 0;
	while (arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
		{
			ft_strarr_free(new_arr);
			return (NULL);
		}
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}
