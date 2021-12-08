/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:36:37 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 14:47:38 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

bool	pipex_cd(t_strlist *lst)
{
	if (!lst)
		return (true);
	chdir(lst->str->text);
	return (true);
}
