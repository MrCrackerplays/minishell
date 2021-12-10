/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variable_expansion.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 17:16:44 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/10 13:59:32 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <variable_expansion.h>
#include <pipex.h>

int	insert_variable(size_t i, char *line, t_string *expanded)
{
	size_t		offset;
	t_string	*cut;

	offset = i;
	i++;
	if (line[i] == '?')
		i++;
	else
		while (line[i] == '_' || ft_isalnum(line[i]))
			i++;
	if (i > offset + 1)
	{
		cut = ft_str_cut_out(expanded, offset, i - offset);
		if (cut == NULL)
			return (-1);
		if (get_env_var(cut->text + 1) != NULL)
			ft_str_insert_s(expanded, get_env_var(cut->text + 1), offset);
		else
			ft_str_insert(expanded, cut, offset);
		ft_str_free(cut);
	}
	return (0);
}

t_string	*expand_variables(char *line)
{
	t_string	*expanded;
	size_t		i;
	int			is_quoted;

	expanded = ft_str_new(line);
	if (expanded == NULL)
		return (NULL);
	i = expanded->len;
	is_quoted = 0;
	while (i > 0)
	{
		if (line[i] == '\'')
			is_quoted = !is_quoted;
		if (!is_quoted && line[i] == '$'
			&& insert_variable(i, line, expanded) != 0)
		{
			ft_str_free(expanded);
			return (NULL);
		}
		i--;
	}
	return (expanded);
}
