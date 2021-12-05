/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:28:05 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/05 13:26:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *d, char *s)
{
	char	*string;
	char	*string_parse;

	if (!d || !s)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(d) + ft_strlen(s) + 1));
	if (!string)
		return (NULL);
	string_parse = string;
	while (*d)
	{
		*string_parse = *d;
		string_parse++;
		d++;
	}
	while (*s)
	{
		*string_parse = *s;
		string_parse++;
		s++;
	}
	*string_parse = '\0';
	return (string);
}
