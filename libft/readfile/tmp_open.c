/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp_open.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 15:28:09 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/07 16:20:30 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "fcntl.h"

int	ft_tmp_open(char *name, int mode)
{
	t_string	*tmp;
	int			out;

	tmp = ft_str_new(getenv("TMPDIR"));
	if (!tmp)
		ft_exit_error("libft malloc fail");
	ft_str_cat_s(tmp, name);
	out = open(tmp->text, mode, 0777);
	ft_str_free(tmp);
	return (out);
}
