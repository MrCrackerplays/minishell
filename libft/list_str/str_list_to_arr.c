/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_list_to_arr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 12:26:28 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/07 15:53:36 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_str.h"

char	**ft_strlst_to_arr(t_strlist *lst)
{
	char		**arr;
	int			i;
	t_strlist	*lst_p;

	arr = ft_calloc(ft_strlst_size(lst) + 1, sizeof(char *));
	i = 0;
	lst_p = lst;
	while (lst_p && lst_p->str)
	{
		arr[i] = ft_strdup(lst_p->str->text);
		if (!arr[i])
		{
			ft_strarr_free(arr);
			return (NULL);
		}
		lst_p = lst_p->next;
		i++;
	}
	return (arr);
}
