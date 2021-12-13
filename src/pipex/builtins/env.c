/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 18:42:45 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 14:56:11 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

void	pipex_env(t_pipex_data *data)
{
	t_strlist	*tmp;

	tmp = get_t_vars()->env;
	while (tmp)
	{
		ft_putendl_fd(tmp->str->text, which_out(data));
		tmp = tmp->next;
	}
}
