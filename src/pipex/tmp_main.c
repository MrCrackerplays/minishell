/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_tmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 15:25:25 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 13:13:45 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_strlist	*lst;

	i = 1;
	lst = NULL;
	while (argv[i])
	{
		ft_strlst_add_back(&lst, ft_strlst_new(ft_str_new(argv[i])));
		i++;
	}
	pipex(lst, envp);
	ft_printf("\n-~{ END }~-\n");
	exit(0);
}
