/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_null.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 19:43:33 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/03 19:43:55 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_free_n1(void **i1)
{
	if (*i1)
		free(*i1);
	*i1 = NULL;
}

void	ft_free_n2(void **i1, void **i2)
{
	if (*i1)
		free(*i1);
	*i1 = NULL;
	if (*i2)
		free(*i2);
	*i2 = NULL;
}

void	ft_free_n3(void **i1, void **i2, void **i3)
{
	if (*i1)
		free(*i1);
	*i1 = NULL;
	if (*i2)
		free(*i2);
	*i2 = NULL;
	if (*i3)
		free(*i3);
	*i3 = NULL;
}

void	ft_free_n4(void **i1, void **i2, void **i3, void **i4)
{
	if (*i1)
		free(*i1);
	*i1 = NULL;
	if (*i2)
		free(*i2);
	*i2 = NULL;
	if (*i3)
		free(*i3);
	*i3 = NULL;
	if (*i4)
		free(*i4);
	*i4 = NULL;
}
