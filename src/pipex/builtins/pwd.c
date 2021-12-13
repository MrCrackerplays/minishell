/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:31:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 14:55:56 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

void	pipex_pwd(t_pipex_data *data)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	ft_putendl_fd(tmp, which_out(data));
	free(tmp);
}
