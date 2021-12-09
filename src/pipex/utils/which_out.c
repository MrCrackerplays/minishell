/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   which_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:46:49 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/09 16:46:58 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

int	which_out(t_pipex_data *data)
{
	if (data->std_out)
		return (1);
	return (data->p[1]);
}
