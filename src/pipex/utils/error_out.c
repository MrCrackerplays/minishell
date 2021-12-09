/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 17:49:35 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/09 18:32:31 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

void	write_error_num(int num)
{
	int		fd;
	char	*tmp;

	num /= 256;
	fd = ft_tmp_open(TMP_ERROR, O_RDWR | O_CREAT | O_TRUNC);
	ft_putnbr_fd(num, fd);
	close(fd);
	tmp = ft_tmp_read(TMP_ERROR);
	ft_str_copy_to_s(get_t_vars()->last_out, tmp);
	free(tmp);
}
