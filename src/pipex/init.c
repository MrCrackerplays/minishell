/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 17:31:54 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 13:51:46 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

t_pipex_data	*pipex_data_new(void)
{
	t_pipex_data	*data;

	data = ft_malloc_e(sizeof(t_pipex_data), "minishell");
	data->p[0] = -1;
	data->p[1] = -1;
	data->p_switch = true;
	close(ft_tmp_open(TMP_PIP1, O_WRONLY | O_CREAT | O_TRUNC));
	close(ft_tmp_open(TMP_PIP2, O_WRONLY | O_CREAT | O_TRUNC));
	close(ft_tmp_open(TMP_HERE, O_WRONLY | O_CREAT | O_TRUNC));
	data->com = NULL;
	data->out = NULL;
	pipex_data_clear(data);
	return (data);
}

void	pipex_data_clear(t_pipex_data *data)
{
	data->std_in = true;
	data->std_out = true;
	data->out_add = false;
	if (data->out)
		ft_str_free(data->out);
	data->out = NULL;
	data->in = NULL;
	data->make = NULL;
	data->use_tmp = false;
	if (data->com)
		ft_strlst_free(data->com);
	data->com = NULL;
	pipe_close(data->p);
	data->p_switch = !data->p_switch;
	if (data->p_switch)
	{
		data->p[0] = ft_tmp_open(TMP_PIP1, O_RDONLY | O_CREAT);
		data->p[1] = ft_tmp_open(TMP_PIP2, O_WRONLY | O_CREAT | O_TRUNC);
	}
	else
	{
		data->p[0] = ft_tmp_open(TMP_PIP2, O_RDONLY | O_CREAT);
		data->p[1] = ft_tmp_open(TMP_PIP1, O_WRONLY | O_CREAT | O_TRUNC);
	}
}
