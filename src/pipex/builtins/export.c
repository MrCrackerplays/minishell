/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 19:07:27 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/09 13:31:11 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

static void	remove_from_env(t_string *str)
{
	t_strlist	*og_lst;
	t_strlist	*lst;
	int			len;
	t_vars		*vars;

	len = 0;
	while (str->text[len] != '=')
		len++;
	vars = get_t_vars();
	og_lst = vars->env;
	lst = og_lst;
	while (lst)
	{
		if (ft_strncmp(lst->str->text, str->text, len) == 0)
		{
			ft_strlst_remove_free(&vars->env, lst);
			return ;
		}
		lst = lst->next;
	}
}

void	pipex_export(t_strlist *lst)
{
	int			len;

	if (!lst)
		return ;
	len = 0;
	while (lst->str->text[len] != '=')
	{
		if (!ft_isalpha(lst->str->text[len])
			&& !ft_isdigit(lst->str->text[len])
			&& lst->str->text[len] != '_')
		{
			len = -1;
			break ;
		}
		len++;
	}
	if (len != -1 && ft_strchr(lst->str->text, '='))
	{
		remove_from_env(lst->str);
		ft_strlst_add_back(&get_t_vars()->env,
			ft_strlst_new(ft_str_copy(lst->str)));
	}
	pipex_export(lst->next);
}
