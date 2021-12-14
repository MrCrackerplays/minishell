/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:25:29 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/14 13:26:30 by rdrazsky      ########   odam.nl         */
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

static void	set_quote_and_i(t_string *cut, size_t *i, char *quote)
{
	if ((cut->text[*i] == '\'' || cut->text[*i] == '"')
		&& ft_strchr(cut->text + *i + 1, cut->text[*i]))
	{
		*quote = cut->text[*i];
		(*i)++;
	}
}

static int	is_end_of_block2(char quote, char *cut, size_t *i)
{
	if (cut[*i] == '\0')
		return (1);
	if (cut[*i] == quote)
		return (1);
	if (quote == '\0' && (cut[*i] == '\'' || cut[*i] == '"')
		&& ft_strchr(cut + *i + 1, cut[*i]))
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
	i = 0;
	while (cut->text[i] != '\0')
	{
		quote = '\0';
		set_quote_and_i(cut, &i, &quote);
		start = i;
		while (!is_end_of_block2(quote, cut->text, &i))
			i++;
		if (i - start > 0 && add_result(result, ft_str_cut(cut, start,
					i - start)) == NULL)
			return (NULL);
		if (quote)
			i++;
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
