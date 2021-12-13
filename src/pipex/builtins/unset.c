/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 18:57:36 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 15:02:45 by rdrazsky      ########   odam.nl         */
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

static void	print_error_msg(char *error)
{
	ft_putstr_fd("minishell: unset: '", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("': not a valid identifier\n", 1);
	write_error_num(1);
}

void	pipex_unset(t_strlist *lst)
{
	int			len;

	while (lst)
	{
		len = 0;
		while (lst->str->text[len] != '\0')
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
		if (len == -1
			|| (lst->str->text[0] != '_' && !ft_isalpha(lst->str->text[0])))
			print_error_msg(lst->str->text);
		else if (len > 0)
			remove_from_env(lst->str);
		lst = lst->next;
	}
}
