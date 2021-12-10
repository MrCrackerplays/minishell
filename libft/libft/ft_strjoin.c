/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:14:22 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:38:38 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Return joined strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		s1l;
	int		s2l;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	string = (char *) ft_malloc_e(sizeof(char) * (s1l + s2l + 1), "libft");
	ft_strlcpy(string, s1, s1l + 1);
	ft_strlcpy(string + s1l, s2, s2l + 1);
	return (string);
}
