/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 14:12:34 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/08 13:58:03 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <libft.h>
#include <line_parser.h>

void	read_and_execute(void)
{
	char		*str;
	t_strlist	*lst;

	while (1)
	{
		str = readline(">");
		if (!str || ft_strncmp(str, "exit", ft_strlen(str)) == 0)
			break ;
		lst = parse_line(str);
		printf("parsed line\n");
		ft_strlst_print(lst);
		ft_strlst_free(lst);
	}
}

int	main(void)
{
	read_and_execute();
}
