/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vars.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 17:23:17 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 13:40:31 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

t_vars	*get_t_vars(void)
{
	static t_vars	vars;

	return (&vars);
}

static void	increase_shell_lvl(void)
{
	int			lvl;
	char		*tmp;
	t_string	*str;
	t_strlist	*lst;

	tmp = getenv("SHLVL");
	if (tmp)
	{
		lvl = ft_atoi(tmp) + 1;
		tmp = ft_itoa(lvl);
		if (tmp)
		{
			str = ft_str_new("SHLVL=");
			ft_str_cat_s(str, tmp);
			free(tmp);
		}
		else
			str = ft_str_new("SHLVL=1");
	}
	else
		str = ft_str_new("SHLVL=1");
	lst = ft_strlst_new(str);
	pipex_export(lst);
	ft_strlst_free(lst);
}

void	t_vats_init(char **envp)
{
	t_vars		*vars;

	vars = get_t_vars();
	vars->env = NULL;
	while (*envp)
	{
		ft_strlst_add_back(&vars->env, ft_strlst_new(ft_str_new(*envp)));
		envp++;
	}
	vars->last_out = ft_str_new("0");
	vars->std_out = dup(1);
	increase_shell_lvl();
	write_error_num(0);
	vars->in_readline = false;
	vars->reload_mutex = true;
}

char	*get_env_var(char *name)
{
	t_strlist	*lst;
	char		*tmp;

	if (ft_strncmp(name, "?", 2) == 0)
		return (get_t_vars()->last_out->text);
	lst = get_t_vars()->env;
	while (lst)
	{
		tmp = ft_strchr(lst->str->text, '=');
		if (ft_strncmp(lst->str->text, name,
				ft_max(tmp - lst->str->text, ft_strlen(name))) == 0)
			return (tmp + 1);
		lst = lst->next;
	}
	return (NULL);
}
