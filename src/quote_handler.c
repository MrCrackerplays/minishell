/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:25:29 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/13 14:07:21 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <quote_handler.h>

t_string	*add_result(t_string *result, t_string *quoteless)
{
	if (quoteless == NULL)
	{
		ft_str_free(result);
		return (NULL);
	}
	ft_str_cat(result, quoteless);
	ft_str_free(quoteless);
	return (result);
}

char	get_replacement_quote(char current_quote, char first)
{
	if (current_quote != '\0')
	{
		if (current_quote == first)
			return ('\0');
		return (current_quote);
	}
	if (first == '\'' || first == '"')
		return (first);
	return ('\0');
}

int	is_end_of_block(char quote, char current)
{
	if (current == '\0')
		return (1);
	if (current == quote)
		return (1);
	if (quote == '\0' && (current == '\'' || current == '"'))
		return (1);
	return (0);
}

t_string	*quote_handling(t_string *cut)
{
	size_t		i;
	size_t		start;
	char		quote;
	t_string	*result;

	result = ft_str_new("");
	if (result == NULL)
		return (NULL);
	i = 0;
	quote = '\0';
	while (cut->text[i] != '\0')
	{
		quote = get_replacement_quote(quote, cut->text[i]);
		if (cut->text[i] == '\'' || cut->text[i] == '"')
			i++;
		start = i;
		while (!is_end_of_block(quote, cut->text[i]))
			i++;
		if (i - start > 0 && add_result(result, ft_str_cut(cut, start,
					i - start)) == NULL)
			return (NULL);
	}
	return (result);
}

t_string	*quote_handling_free(t_string *cut)
{
	t_string	*ret;

	if (cut == NULL)
		return (NULL);
	ret = quote_handling(cut);
	ft_str_free(cut);
	return (ret);
}
