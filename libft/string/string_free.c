/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 16:29:37 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 16:29:37 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_str_strip(t_string *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = str->text;
	free(str);
	return (tmp);
}

void	ft_str_free(t_string *str)
{
	free(str->text);
	free(str);
}
