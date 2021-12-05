/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_split.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 16:53:41 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/03 18:54:03 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static t_strlist	*add_to_list(t_strlist *lst, int i, char *b)
{
	t_strlist	*tmp;

	tmp = ft_strlst_new(ft_str_new_l(b, i));
	if (!tmp)
	{
		ft_strlst_free(lst);
		return (NULL);
	}
	ft_strlst_add_back(&lst, tmp);
	return (lst);
}

t_strlist	*ft_str_split(char *s, char c)
{
	t_strlist	*lst;
	char		*b;
	int			i;

	lst = NULL;
	b = s;
	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			lst = add_to_list(lst, i, b);
			if (!lst)
				return (NULL);
			i = 0;
			b = (char *) s + 1;
		}
		else
			i++;
		s++;
	}
	lst = add_to_list(lst, i, b);
	if (!lst)
		return (NULL);
	return (lst);
}
