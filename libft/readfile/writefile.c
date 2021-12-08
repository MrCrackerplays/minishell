/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writefile.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 16:49:56 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/07 14:56:38 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "fcntl.h"

void	ft_writefile(char *name, char *text)
{
	int	fd;

	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	ft_putstr_fd(text, fd);
	close(fd);
}

void	ft_writefile_ms(char *name, t_string *str)
{
	int	fd;

	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	write(fd, str->text, str->len);
	close(fd);
}

void	ft_addfile(char *name, char *text)
{
	int	fd;

	fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0777);
	ft_putstr_fd(text, fd);
	close(fd);
}

void	ft_addfile_ms(char *name, t_string *str)
{
	int	fd;

	fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0777);
	write(fd, str->text, str->len);
	close(fd);
}
