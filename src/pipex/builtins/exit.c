/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 14:42:19 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 14:42:37 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

void	pipex_exit(void)
{
	ft_putendl_fd("exit", 1);
	exit(0);
}
