/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:28:05 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(d);
	slen = ft_strlen(s);
	if (n < dlen + 1)
		return (slen + n);
	d += dlen;
	while (*s && dlen < n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	if (dlen == n)
	{
		d--;
		*d = '\0';
	}
	else
		*d = '\0';
	return (dlen + slen);
}
