/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipe_close.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 14:20:00 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 12:43:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipe_close(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}
