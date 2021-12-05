/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:24:30 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	d = (char *) dst;
	s = (char *) src;
	while (n)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dst);
}
