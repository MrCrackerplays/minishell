/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:36:37 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/16 13:01:22 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>

#include <pipex_internal.h>

void	pipex_cd(t_strlist *lst)
{
	struct stat	path_stat;
	int			error;

	if (!lst)
		return ;
	if (ft_strncmp(lst->str->text, "~", 2) == 0)
		error = chdir(getenv("HOME"));
	else
		error = chdir(lst->str->text);
	if (error == -1)
	{
		stat(lst->str->text, &path_stat);
		ft_putstr_fd("minishell: cd: ", 1);
		ft_putstr_fd(lst->str->text, 1);
		if (path_stat.st_mode)
			ft_putendl_fd(": Not a directory", 1);
		else
			ft_putendl_fd(": No such file or directory", 1);
		write_error_num(1);
	}
}
