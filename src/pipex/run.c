/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:45:13 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 14:19:37 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static bool	buildins(t_pipex_data *data, char **envp)
{
	if (ft_strncmp(data->com->str->text, "echo", 5) == 0)
		pipex_echo(data->com->next, data);
	else if (ft_strncmp(data->com->str->text, "pwd", 4) == 0)
		pipex_pwd(data);
	else if (ft_strncmp(data->com->str->text, "cd", 3) == 0)
		pipex_cd(data->com->next);
	else
		return (false);
	return (true);
}

static	void	child_run(t_pipex_data *data, char **envp)
{
	if (data->in)
		data->p[0] = open(data->in->text, O_RDONLY);
	else if (data->use_tmp)
		data->p[0] = ft_tmp_open(TMP_HERE, O_RDONLY);
	if (data->out && data->out_add)
		data->p[1] = open(data->out->text, O_RDWR | O_CREAT | O_APPEND, 0777);
	else if (data->out && !data->out_add)
		data->p[1] = open(data->out->text, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (dup2(data->p[0], 0) == -1 || dup2(data->p[1], 1) == -1)
		ft_exit_error("dup fail");
	if (buildins(data, envp))
		exit(0);
	exec3(data->com, envp);
}

void	pipex_run_command(t_pipex_data *data, char **envp)
{
	int			pid;
	t_strlist	*tmp;

	while (data->make)
	{
		if (access(data->make->str->text, 0))
			close(open(data->make->str->text, O_CREAT | O_TRUNC, 0777));
		tmp = data->make->next;
		data->make->next = NULL;
		ft_strlst_free(data->make);
		data->make = tmp;
	}
	if (!data->com)
		return ;
	pid = fork();
	if (pid == -1)
		ft_exit_error("pid fail");
	if (pid == 0)
		child_run(data, envp);
	wait(0);
}
