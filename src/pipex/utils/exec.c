/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:39:34 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:43:54 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>
#include <errno.h>

void	exec(int in, int out, char *arg, char **envp)
{
	char		**str;
	char		*arg2;
	t_strlist	*tmp;

	arg2 = get_arg(arg, envp);
	if (!arg2)
	{
		tmp = ft_str_split(arg, ' ');
		ft_printf("command not found: %s\n", tmp->str->text);
		ft_strlst_free(tmp);
		return ;
	}
	str = ft_split(arg2, ' ');
	dup2(out, 1);
	dup2(in, 0);
	execve(str[0], str, envp);
}

void	exec2(int in, int out, t_strlist *lst, char **envp)
{
	char		**arr;
	bool		is_env;

	is_env = get_arg2(lst->str);
	if (access(lst->str->text, 0))
		ft_exit_error("no such file or command");
	else if (!is_env && ft_strncmp(lst->str->text, "./", 2) != 0)
		ft_exit_error("no such command");
	arr = ft_strlst_to_arr(lst);
	if (!arr)
		ft_exit_error("malloc fail");
	if (dup2(out, 1) == -1 || dup2(in, 0) == -1)
		ft_exit_error("dup fail");
	execve(lst->str->text, arr, envp);
	perror("execve fail");
}

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
		ft_putstr_fd(": Command not found\n", get_t_vars()->std_out);
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
