/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:15:38 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 14:11:22 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

bool	pipex_echo(t_strlist *lst, t_pipex_data *data)
{
	t_strlist	*tmp;

	if (!lst)
		return (true);
	tmp = lst;
	if (ft_strncmp(lst->str->text, "-n", 3) == 0)
		tmp = lst->next;
	while (tmp)
	{
		write(1, tmp->str->text, tmp->str->len);
		if (tmp->next)
			ft_putchar_fd(' ', data->p[1]);
		tmp = tmp->next;
	}
	if (ft_strncmp(lst->str->text, "-n", 3))
		ft_putchar_fd('\n', data->p[1]);
	return (true);
}
