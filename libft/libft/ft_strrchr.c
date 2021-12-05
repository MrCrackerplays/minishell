/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:36:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*ptr;

	ch = (char) c;
	ptr = NULL;
	while (*s)
	{
		if (*s == ch)
			ptr = (char *) s;
		s++;
	}
	if (*s == ch)
		ptr = (char *) s;
	return (ptr);
}
