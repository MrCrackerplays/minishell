/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 18:15:10 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/03 19:37:55 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_str_insert(t_string *d, t_string *s, size_t index)
{
	char	*tmp;

	if (!s || s->len == 0 || index > d->len)
		return ;
	if (d->len == index)
	{
		ft_str_cat(d, s);
		return ;
	}
	tmp = malloc(sizeof(char) * (d->len + s->len + 1));
	ft_str_write_d(tmp, d->text, index);
	ft_str_write_d(tmp + index, s->text, s->len);
	ft_str_write_d(tmp + index + s->len,
		d->text + index,
		d->len - index);
	free(d->text);
	d->text = tmp;
	d->len = d->len + s->len;
}

void	ft_str_insert_s(t_string *d, char *s, size_t index)
{
	t_string	*tmp;

	tmp = ft_str_new(s);
	ft_str_insert(d, tmp, index);
	ft_str_free(tmp);
}
