/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 17:29:03 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 14:47:21 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

void	pipex_heredoc(t_strlist *lst, t_pipex_data *data)
{
	char		*tmp;
	t_string	*file;

	if (data->in)
		data->in = NULL;
	data->use_tmp = true;
	file = ft_str_new("");
	ft_putstr_fd(">", 1);
	tmp = ft_get_next_line(0);
	while (ft_strncmp(tmp, lst->str->text, lst->str->len) != 0)
	{
		ft_str_cat_s(file, tmp);
		ft_putstr_fd(">", 1);
		tmp = ft_get_next_line(0);
	}
	ft_tmp_write_ms(TMP_HERE, file);
	ft_str_free(file);
}
