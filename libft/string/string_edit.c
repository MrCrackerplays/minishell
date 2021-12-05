/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_edit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 19:08:04 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/03 19:41:44 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_str_write_d(char *des, char *src, size_t len)
{
	size_t	i;

	if (!des || !src)
		return ;
	i = 0;
	while (i < len && src[i])
	{
		des[i] = src[i];
		i++;
	}
	des[len] = '\0';
}

void	ft_str_cat(t_string *des, t_string *src)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (des->len + src->len + 1));
	if (!tmp)
		return ;
	ft_str_write_d(tmp, des->text, des->len);
	ft_str_write_d(tmp + des->len, src->text, src->len);
	free(des->text);
	des->text = tmp;
	des->len = des->len + src->len;
}
