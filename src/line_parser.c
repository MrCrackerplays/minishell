/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 14:49:49 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/09 13:56:40 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <line_parser.h>
#include <quote_handler.h>

int	should_split(t_string *line, size_t *i, char *quoted)
{
	if (line->text[*i] == *quoted)
		*quoted = '\0';
	else if (*quoted == '\0')
	{
		if (line->text[*i] == '\'')
			*quoted = '\'';
		else if (line->text[*i] == '"')
			*quoted = '"';
		else
			*quoted = '\0';
	}
	if (*quoted)
		return (0);
	if (line->text[*i] == ' ' || line->text[*i] == '|'
		|| line->text[*i] == '<' || line->text[*i] == '>')
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

int	pipe_parse(char *c, t_strlist **lst, size_t *i)
{
	char	*additive;

	additive = "|";
	if (*c == '<')
		additive = "<";
	else if (*c == '<' && c[1] == '<')
		additive = "<<";
	else if (*c == '>')
		additive = ">";
	else if (*c == '>' && c[1] == '>')
		additive = ">>";
	if ((*c == '>' || *c == '<') && c[0] == c[1])
		(*i)++;
	if (*c == '|' || *c == '<' || *c == '>')
		(*i)++;
	if ((*c == '|' || *c == '<' || *c == '>')
		&& add_to_lst(lst, ft_str_new(additive)) != 0)
		return (-1);
	return (0);
}

int	apply_parse(t_strlist **lst, t_string *str_line, size_t offset, size_t i)
{
	int	result;

	result = add_to_lst(lst, quote_handling_free(
				ft_str_cut(str_line, offset, i - offset))) != 0
		|| pipe_parse(str_line->text + i, &lst, &i) != 0;
	if (result)
	{
		ft_str_free(str_line);
		ft_strlst_free(lst);
	}
	return (result);
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
			i++;
		if (i != offset && apply_parse(&lst, str_line, offset, i))
			return (NULL);
		while (line[i] == ' ')
			i++;
		offset = i;
	}
	ft_str_free(str_line);
	return (lst);
}
