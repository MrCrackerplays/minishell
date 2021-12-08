/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 17:46:55 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 19:06:11 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

static bool	var_valid_name(char *s)
{
	while (*s != '=')
	{
		if (!ft_isalpha(*s) || !ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

static void	remove_from_env(t_string *str)
{
	t_strlist	*og_lst;
	t_strlist	*lst;
	int			len;

	len = 0;
	while (str->text[len] != '=')
		len++;
	og_lst = get_t_vars()->env;
	lst = og_lst;
	while (lst)
	{
		if (ft_strncmp(lst->str->text, str->text, len) == 0)
		{
			ft_strlst_remove_free(&og_lst, lst);
			return ;
		}
		lst = lst->next;
	}
}

bool	pipex_assign(t_strlist *lst)
{
	if (!lst)
		return (false);
	if (lst->str->text[0] == '=')
		return (false);
	if (!ft_strchr(lst->str->text, '='))
		return (false);
	if (!var_valid_name(lst->str->text))
	{
		remove_from_env(lst->str);
		ft_strlst_add_back(&get_t_vars()->env,
			ft_strlst_new(ft_str_new(lst->str->text)));
	}
	else
		return (false);
	pipex_assign(lst->next);
	return (true);
}
