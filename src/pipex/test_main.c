/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp_main.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 15:25:25 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/08 19:34:13 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_internal.h>

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_strlist	*lst;

	t_vats_init(envp);
	i = 1;
	lst = NULL;
	while (argv[i])
	{
		ft_strlst_add_back(&lst, ft_strlst_new(ft_str_new(argv[i])));
		i++;
	}
	ft_strlst_print_s(lst, " ");
	pipex(lst);
	ft_printf("\n-~{ END }~-\n");
	while (true)
		continue ;
	exit(0);
}
