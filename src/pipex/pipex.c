/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:40:35 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 17:36:23 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

static void	pipex_stdout(bool p_switch)
{
	char	*file;

	if (p_switch)
		file = ft_tmp_read(TMP_PIP2);
	else
		file = ft_tmp_read(TMP_PIP1);
	ft_putstr_fd(file, 1);
	free(file);
}

static void	clear_tmp(t_pipex_data *data)
{
	if (data->std_out)
		pipex_stdout(data->p_switch);
	close(ft_tmp_open(TMP_PIP1, O_CREAT | O_TRUNC));
	close(ft_tmp_open(TMP_PIP2, O_CREAT | O_TRUNC));
}

void	pipex(t_strlist *lst)
{
	t_pipex_data	*data;

	data = pipex_data_new();
	while (lst)
	{
		pipex_data_clear(data);
		pipex_init_io(data, lst);
		pipex_run_command(data);
		while (lst)
		{
			if (ft_strncmp(lst->str->text, "|", 2) == 0
				|| ft_strncmp(lst->str->text, ";", 2) == 0)
			{
				if (ft_strncmp(lst->str->text, ";", 2) == 0)
					clear_tmp(data);
				lst = lst->next;
				break ;
			}
			lst = lst->next;
		}
	}
	if (data->std_out)
		pipex_stdout(data->p_switch);
}
