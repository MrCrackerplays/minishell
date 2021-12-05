/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 18:52:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/03 18:53:15 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_string	*ft_str_new(char *src)
{
	t_string	*des;
	size_t		len;

	len = ft_strlen(src);
	des = malloc(sizeof(t_string));
	if (!des)
		return (NULL);
	des->text = ft_calloc(len + 1, sizeof(char));
	if (!des->text)
	{
		free(des);
		return (NULL);
	}
	ft_str_write_d(des->text, src, len);
	des->len = len;
	return (des);
}

t_string	*ft_str_new_l(char *src, size_t len)
{
	t_string	*des;

	des = malloc(sizeof(t_string));
	if (!des)
		return (NULL);
	des->text = ft_calloc(len + 1, sizeof(char));
	if (!des->text)
	{
		free(des);
		return (NULL);
	}
	ft_str_write_d(des->text, src, len);
	des->len = len;
	return (des);
}
