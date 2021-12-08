/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 15:08:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/07 16:15:40 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>

char	*ft_tmp_read(char *name)
{
	return (ft_readfile(ft_tmp_open(name, O_RDONLY)));
}

void	ft_tmp_write(char *name, char *text)
{
	t_string	*tmp;

	tmp = ft_str_new(getenv("TMPDIR"));
	if (!tmp)
		ft_exit_error("libft malloc fail");
	ft_str_cat_s(tmp, name);
	ft_writefile(tmp->text, text);
	ft_str_free(tmp);
}

void	ft_tmp_write_ms(char *name, t_string *str)
{
	t_string	*tmp;

	tmp = ft_str_new(getenv("TMPDIR"));
	if (!tmp)
		ft_exit_error("libft malloc fail");
	ft_str_cat_s(tmp, name);
	ft_writefile_ms(tmp->text, str);
	ft_str_free(tmp);
}

void	ft_tmp_add(char *name, char *text)
{
	t_string	*tmp;

	tmp = ft_str_new(getenv("TMPDIR"));
	if (!tmp)
		ft_exit_error("libft malloc fail");
	ft_str_cat_s(tmp, name);
	ft_addfile(tmp->text, text);
	ft_str_free(tmp);
}

void	ft_tmp_add_ms(char *name, t_string *str)
{
	t_string	*tmp;

	tmp = ft_str_new(getenv("TMPDIR"));
	if (!tmp)
		ft_exit_error("libft malloc fail");
	ft_str_cat_s(tmp, name);
	ft_addfile_ms(tmp->text, str);
	ft_str_free(tmp);
}
