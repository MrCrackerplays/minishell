/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:08:04 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Make new string and apply function on each character
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		index;

	if (!s || !*s)
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	string = ft_strdup(s);
	if (!string)
		return (NULL);
	index = 0;
	while (s[index])
	{
		string[index] = (*f)(index, s[index]);
		index++;
	}
	return (string);
}
