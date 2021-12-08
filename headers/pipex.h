/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:45:24 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 17:36:08 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>

typedef struct s_vars{
	t_strlist	*vars;
	t_strlist	*env;
}	t_vars;

t_vars	*get_t_vars(void);
void	t_vats_init(char **envp);

void	pipex(t_strlist *lst);

#endif
