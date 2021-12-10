/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:31:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:38:10 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	int		len;

	len = ft_strlen(s) + 1;
	string = (char *) ft_malloc_e(sizeof(char) * len, "libft");
	ft_strlcpy(string, s, len);
	return (string);
}
