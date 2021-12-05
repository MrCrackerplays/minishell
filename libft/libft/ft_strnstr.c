/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:30:39 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	bi;
	size_t	li;

	if (big == little || ft_strlen(little) == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	bi = 0;
	while (big[bi] && bi < len)
	{
		if (big[bi] == little[0])
		{
			li = 0;
			while (big[bi + li] == little[li])
			{
				li++;
				if (!little[li])
					return ((char *) big + bi);
				if (bi + li >= len)
					return (NULL);
			}
		}
		bi++;
	}
	return (NULL);
}
