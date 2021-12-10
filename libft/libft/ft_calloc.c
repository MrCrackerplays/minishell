/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:26:12 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:37:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = ft_malloc_e(count * size, "libft");
	ft_bzero(mem, count * size);
	return (mem);
}
