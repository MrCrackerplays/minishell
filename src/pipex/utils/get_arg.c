/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 16:52:17 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 12:43:36 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static bool	get_path(t_string *arg, char **envp)
{
	t_strlist	*lst_og;
	t_strlist	*lst;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (false);
	lst_og = ft_str_split(*envp + 5, ':');
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

char	*get_arg(char *arg, char **envp)
{
	t_string	*arg_s;
	t_string	*tmp;
	int			i;
	bool		args;

	i = 0;
	while (arg[i] != '\0' && arg[i] != ' ')
		i++;
	args = false;
	if (arg[i] == ' ')
		args = true;
	arg[i] = '\0';
	arg_s = ft_str_new_l(arg, ft_strlen(arg));
	if (!arg_s)
		return (NULL);
	if (!get_path(arg_s, envp))
		return (NULL);
	if (args)
	{
		arg[i] = ' ';
		tmp = ft_str_new_l(arg + i, ft_strlen(arg + i));
		ft_str_cat(arg_s, tmp);
		ft_str_free(tmp);
	}
	return (ft_str_strip(arg_s));
}

bool	get_arg2(t_string *arg)
{
	t_strlist	*lst_og;
	t_strlist	*lst;

	lst_og = ft_str_split(getenv("PATH"), ':');
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
