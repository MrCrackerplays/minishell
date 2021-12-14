/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:45:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/14 13:39:32 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>

typedef struct s_vars{
	t_strlist	*vars;
	t_strlist	*env;
	t_string	*last_out;
	int			std_out;
	char		*path;
	bool		in_readline;
	bool		error_skip;
	bool		reload_mutex;
}	t_vars;

void	tc_on(void);
void	tc_off(void);

void	pipex_exit(void);

t_vars	*get_t_vars(void);
void	t_vats_init(char **envp);
char	*get_env_var(char *name);

void	write_error_num(int num);

void	pipex(t_strlist *lst);

#endif
