/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:13:44 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:38:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Return a cutout from string
char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*string;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	s += start;
	string = (char *) ft_malloc_e(sizeof(char) * (len + 1), "libft");
	i = 0;
	while (i < len && s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
