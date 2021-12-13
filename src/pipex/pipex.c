/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:40:35 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 15:44:22 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>
#include <errno.h>

void	pipex(t_strlist *lst)
{
	t_pipex_data	*data;

	data = pipex_data_new();
	while (lst)
	{
		pipex_init_io(data, lst);
		pipex_run_command(data);
		pipex_data_clear(data);
		while (lst)
		{
			if (ft_strncmp(lst->str->text, "|", 2) == 0)
			{
				data->std_in = false;
				lst = lst->next;
				break ;
			}
			lst = lst->next;
		}
	}
	ft_strlst_free(data->com);
	free(data);
}
