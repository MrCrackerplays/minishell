/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 18:57:36 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 19:02:32 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

static void	remove_from_env(t_string *str)
{
	t_strlist	*og_lst;
	t_strlist	*lst;
	int			i;

	og_lst = get_t_vars()->env;
	lst = og_lst;
	while (lst)
	{
		i = 0;
		while (lst->str->text[i] != '=')
			i++;
		if (ft_strncmp(lst->str->text, str->text, i) == 0)
		{
			ft_strlst_remove_free(&og_lst, lst);
			return ;
		}
		lst = lst->next;
	}
}

bool	pipex_unset(t_strlist *lst)
{
	while (lst)
	{
		remove_from_env(lst->str);
		lst = lst->next;
	}
	return (true);
}
