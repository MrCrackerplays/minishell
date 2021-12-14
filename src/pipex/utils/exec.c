/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:39:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 13:01:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>
#include <errno.h>

void	exec3(t_strlist *lst)
{
	char		**arr;
	bool		is_env;

	is_env = get_arg2(lst->str);
	if (access(lst->str->text, 0)
		&& !is_env && lst->str->text[0] != '/'
		&& ft_strncmp(lst->str->text, "./", 2) != 0
		&& ft_strncmp(lst->str->text, "../", 3) != 0)
	{
		ft_putstr_fd("minishell: ", get_t_vars()->std_out);
		ft_putstr_fd(lst->str->text, get_t_vars()->std_out);
		ft_putstr_fd(": command not found\n", get_t_vars()->std_out);
		exit(127);
	}
	else if (access(lst->str->text, 0))
	{
		ft_putstr_fd("minishell: ", get_t_vars()->std_out);
		ft_putstr_fd(lst->str->text, get_t_vars()->std_out);
		ft_putstr_fd(": No such file or directory\n", get_t_vars()->std_out);
		exit(127);
	}
	arr = ft_strlst_to_arr(lst);
	execve(lst->str->text, arr, ft_strlst_to_arr(get_t_vars()->env));
	exit(errno);
}
