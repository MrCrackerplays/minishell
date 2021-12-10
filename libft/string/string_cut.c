/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_cut.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 18:12:13 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:40:50 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_string	*ft_str_cut(t_string *str, size_t start, size_t len)
{
	t_string	*str_new;
	char		*tmp;
	size_t		i;

	if (start > str->len)
		return (NULL);
	tmp = ft_malloc_e(sizeof(char) * (len + 1), "libft");
	i = 0;
	while (str->text[start + i] && i < len)
	{
		tmp[i] = str->text[start + i];
		i++;
	}
	tmp[i] = '\0';
	str_new = ft_malloc_e(sizeof(t_string), "libft");
	str_new->text = tmp;
	str_new->len = i;
	return (str_new);
}

t_string	*ft_str_cut_out(t_string *str, size_t start, size_t len)
{
	t_string	*cut_out;

	if (start > str->len - 1)
		return (NULL);
	cut_out = ft_str_cut(str, start, len);
	if (!cut_out)
		return (NULL);
	if (start + len > str->len)
		len = str->len - start;
	ft_str_write_d(str->text + start,
		str->text + start + len,
		str->len - start - len);
	str->len = str->len - len;
	return (cut_out);
}
