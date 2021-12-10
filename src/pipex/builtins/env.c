/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 18:42:45 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 14:50:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

bool	pipex_env(t_pipex_data *data)
{
	t_strlist	*tmp;

	tmp = get_t_vars()->env;
	while (tmp)
	{
		ft_putendl_fd(tmp->str->text, which_out(data));
		tmp = tmp->next;
	}
	return (true);
}

//ft_putstr_fd("_=", which_out(data));
//ft_putendl_fd(get_t_vars()->path, which_out(data));
