/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 18:42:45 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 18:47:01 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

bool	pipex_env(t_pipex_data *data)
{
	t_strlist	*tmp;

	tmp = get_t_vars()->env;
	while (tmp)
	{
		ft_putendl_fd(tmp->str->text, data->p[1]);
		tmp = tmp->next;
	}
	return (true);
}
