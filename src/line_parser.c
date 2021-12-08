/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 14:49:49 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/08 13:56:15 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <line_parser.h>
#include <quote_handler.h>

char	get_quote(char current_quote, char attempted_quote)
{
	if (current_quote == '\0')
	{
		if (attempted_quote == '\'')
			return ('\'');
		if (attempted_quote == '"')
			return ('"');
		return ('\0');
	}
	if (attempted_quote == current_quote)
		return ('\0');
	return (current_quote);
}

int	should_split(t_string *line, size_t *i, char *quoted)
{
	*quoted = get_quote(*quoted, line->text[*i]);
	if (*quoted)
		return (0);
	if (line->text[*i] == ' ')
		return (1);
	return (0);
}

int	add_to_lst(t_strlist **lst, t_string *cut)
{
	t_strlist	*node;

	if (cut == NULL)
		return (-1);
	node = ft_strlst_new(cut);
	if (node == NULL)
	{
		ft_str_free(cut);
		return (-1);
	}
	ft_strlst_add_back(lst, node);
	return (0);
}

t_strlist	*parse_line(char *line)
{
	t_strlist	*lst;
	size_t		i;
	size_t		offset;
	char		quote;
	t_string	*str_line;

	i = 0;
	offset = 0;
	quote = '\0';
	lst = NULL;
	str_line = ft_str_new(line);
	if (str_line == NULL)
		return (NULL);
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && !should_split(str_line, &i, &quote))
		{
			//todo: add redirects and pipes (<< >> < > |) also stopping the splitting but then also getting added afterwards
			i++;
		}
		if (i != offset && add_to_lst(&lst, quote_handling_free(ft_str_cut(
						str_line, offset, i - offset))) != 0)
		{
			ft_str_free(str_line);
			ft_strlst_free(lst);
			return (NULL);
		}
		while (line[i + 1] == ' ')
			i++;
		i++;
		offset = i;
	}
	ft_str_free(str_line);
	return (lst);
}
