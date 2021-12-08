/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vars.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 17:23:17 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 17:34:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

t_vars	*get_t_vars(void)
{
	static t_vars	vars;

	return (&vars);
}

void	t_vats_init(char **envp)
{
	t_vars		*vars;
	t_string	*tmps;
	t_strlist	*tmpl;

	vars = get_t_vars();
	vars->env = NULL;
	while (*envp)
	{
		tmps = ft_str_new(*envp);
		if (!tmps)
			ft_exit_error("malloc fail");
		tmpl = ft_strlst_new(tmps);
		if (!tmpl)
			ft_exit_error("malloc fail");
		ft_strlst_add_back(&vars->env, tmpl);
		envp++;
	}
	vars->vars = NULL;
}
