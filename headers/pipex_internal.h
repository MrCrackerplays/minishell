/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_internal.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 16:16:27 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 14:01:53 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_INTERNAL_H
# define PIPEX_INTERNAL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# include <libft.h>

# include <pipex.h>

# define TMP_PIP1 "minishell_pipe1.tmp"
# define TMP_PIP2 "minishell_pipe2.tmp"
# define TMP_HERE "minishell_heredoc.tmp"
# define TMP_ERROR "minishell_error.tmp"

typedef struct s_pipex_data{
	bool		use_tmp;
	bool		out_add;
	bool		std_out;
	bool		std_in;
	t_strlist	*make;
	t_string	*out;
	t_string	*in;
	t_strlist	*com;
	int			p[2];
	bool		p_switch;
}	t_pipex_data;

// -~{ Buildins }~- //

void			pipex_echo(t_strlist *lst, t_pipex_data *data);
void			pipex_cd(t_strlist *lst);
void			pipex_pwd(t_pipex_data *data);
void			pipex_export(t_strlist *lst);
void			pipex_unset(t_strlist *lst);
void			pipex_env(t_pipex_data *data);

bool			get_arg2(t_string *arg);

void			exec3(t_strlist *lst);

int				which_out(t_pipex_data *data);

void			pipe_close(int pipe[2]);

t_pipex_data	*pipex_data_new(void);

void			pipex_init_io(t_pipex_data *data, t_strlist *lst);

void			pipex_data_clear(t_pipex_data *data);

void			pipex_heredoc(t_strlist *lst, t_pipex_data *data);

void			pipex_run_command(t_pipex_data *data);

void			pipex(t_strlist *lst);

#endif
