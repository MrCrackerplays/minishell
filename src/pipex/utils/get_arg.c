/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 16:52:17 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 13:01:00 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

bool	get_arg2(t_string *arg)
{
	t_strlist	*lst_og;
	t_strlist	*lst;
	char		*tmp;

	tmp = get_env_var("PATH");
	if (!tmp)
		return (false);
	lst_og = ft_str_split(tmp, ':');
	if (!lst_og)
		return (false);
	lst = lst_og;
	while (lst)
	{
		lst->str->text[lst->str->len] = '/';
		lst->str->len++;
		ft_str_cat(lst->str, arg);
		if (access(lst->str->text, 0) + 1)
		{
			ft_str_copy_to(arg, lst->str);
			ft_strlst_free(lst_og);
			return (true);
		}
		lst = lst->next;
	}
	return (false);
}
