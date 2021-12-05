/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_copy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 19:39:19 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/03 19:39:20 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_string	*ft_str_copy(t_string *str)
{
	return (ft_str_new_l(str->text, str->len));
}

void	ft_str_copy_to(t_string *des, t_string *src)
{
	char	*tmp;

	if (!des || !src)
		return ;
	tmp = ft_calloc(src->len + 1, sizeof(char));
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	ft_str_write_d(tmp, src->text, src->len);
	free(des->text);
	des->text = tmp;
	des->len = src->len;
}
