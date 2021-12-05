/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:27:03 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/05 13:15:59 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
