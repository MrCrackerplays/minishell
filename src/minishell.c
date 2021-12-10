/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 14:12:34 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/10 15:27:13 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <libft.h>
#include <line_parser.h>

#include <pipex.h>

int	quotation_check(char *str)
{
	char	quote;
	size_t	i;

	quote = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (str[i] == quote && quote != '\0')
				quote = '\0';
			else if (quote == '\0')
				quote = str[i];
		}
		i++;
	}
	return (quote != '\0');
}

void	read_and_execute(void)
{
	char		*str;
	t_strlist	*lst;

	while (1)
	{
		str = readline("minishell> ");
		add_history(str);
		if (quotation_check(str))
		{
			ft_putendl_fd("minishell: invalid syntax", 1);
			write_error_num(258 * 256);
			free (str);
			continue ;
		}
		if (ft_strncmp(str, "exit", 5) == 0)
		{
			ft_putendl_fd("exit", 1);
			exit(0);
		}
		lst = parse_line(str);
		// ft_strlst_print(lst);
		pipex(lst);
		ft_strlst_free(lst);
		free(str);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_vats_init(argv, envp);
	read_and_execute();
	if (argc && argv)
		exit(0);
}
