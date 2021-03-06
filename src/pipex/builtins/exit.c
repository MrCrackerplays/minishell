/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 14:42:19 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 19:01:41 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <pipex_internal.h>

void	pipex_exit(void)
{
	tc_off();
	ft_putendl_fd("exit", 1);
	exit(0);
}
