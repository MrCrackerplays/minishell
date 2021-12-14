/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 19:33:03 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 13:52:07 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

static void	set_input(t_pipex_data *data, t_string *str)
{
	data->std_in = false;
	data->in = str;
	data->use_tmp = false;
}

static void	add_to_make(t_pipex_data *data, t_string *str)
{
	t_string	*tmp;

	tmp = ft_str_copy(str);
	if (!tmp)
		ft_exit_error("malloc fail");
	ft_strlst_add_front(&data->make, ft_strlst_new(tmp));
}

static bool	pipex_io(t_strlist *parse, t_pipex_data *data)
{
	bool	is_io;

	is_io = false;
	if (parse->next)
	{
		is_io = true;
		if (ft_strncmp(parse->str->text, ">>", 3) == 0)
		{
			add_to_make(data, parse->next->str);
			data->out_add = true;
		}
		else if (ft_strncmp(parse->str->text, ">", 2) == 0)
		{
			add_to_make(data, parse->next->str);
			data->out_add = false;
		}
		else if (ft_strncmp(parse->str->text, "<<", 3) == 0)
			pipex_heredoc(parse->next, data);
		else if (ft_strncmp(parse->str->text, "<", 2) == 0)
			set_input(data, parse->next->str);
		else
			is_io = false;
	}
	return (is_io);
}

void	pipex_init_io(t_pipex_data *data, t_strlist *lst)
{
	t_strlist		*parse;

	parse = lst;
	while (parse)
	{
		if (ft_strncmp(parse->str->text, "|", 2) == 0)
			break ;
		if (!pipex_io(parse, data))
		{
			ft_strlst_add_back(&data->com,
				ft_strlst_new(ft_str_copy(parse->str)));
			parse = parse->next;
		}
		else
			parse = parse->next->next;
	}
	if (data->make)
		data->out = ft_str_copy(data->make->str);
	if (data->make || (parse && ft_strncmp(parse->str->text, "|", 2) == 0))
		data->std_out = false;
}
