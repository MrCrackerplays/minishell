/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tc.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 18:59:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/13 19:01:03 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>
#include <termios.h>

void	tc_on(void)
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
}

void	tc_off(void)
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	if (!(attributes.c_lflag & ECHOCTL))
		attributes.c_lflag += ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
}
