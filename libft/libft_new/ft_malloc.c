/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:33:14 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:35:41 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_malloc(size_t size)
{
	void	*item;

	item = malloc(size);
	if (!item)
		perror(NULL);
	return (item);
}

void	*ft_malloc_e(size_t size, char *error)
{
	void	*item;

	item = malloc(size);
	if (!item)
		perror(error);
	return (item);
}
