/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit_error.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 18:07:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:27:49 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_exit_error(char *error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(1);
}

void	ft_exit_error_n(char *error, int error_no)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(error_no);
}
