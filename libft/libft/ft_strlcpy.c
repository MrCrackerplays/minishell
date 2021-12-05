/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:27:19 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	int		slen;

	slen = ft_strlen(s);
	if (n == 0)
		return (slen);
	while (*s && n - 1)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	if (n == 0)
		d--;
	*d = '\0';
	return (slen);
}
