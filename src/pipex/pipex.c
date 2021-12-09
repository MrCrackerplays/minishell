/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:40:35 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/09 16:56:28 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

static void	clear_tmp(void)
{
	close(ft_tmp_open(TMP_PIP1, O_CREAT | O_TRUNC));
	close(ft_tmp_open(TMP_PIP2, O_CREAT | O_TRUNC));
}

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
			if (ft_strncmp(lst->str->text, "|", 2) == 0
				|| ft_strncmp(lst->str->text, ";", 2) == 0)
			{
				if (ft_strncmp(lst->str->text, ";", 2) == 0)
					clear_tmp();
				else
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
