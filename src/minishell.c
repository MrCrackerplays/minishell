/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 14:12:34 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/13 14:47:37 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <libft.h>
#include <line_parser.h>
#include <termios.h>

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
	if (quote != '\0')
	{
		ft_putendl_fd("minishell: invalid syntax", 1);
		write_error_num(258);
		free (str);
	}
	return (quote != '\0');
}

void	read_and_execute(void)
{
	char		*str;
	t_strlist	*lst;

	while (1)
	{
		get_t_vars()->in_readline = true;
		str = readline("minishell> ");
		if (!str)
			pipex_exit();
		get_t_vars()->in_readline = false;
		add_history(str);
		if (quotation_check(str))
			continue ;
		lst = parse_line(str);
		pipex(lst);
		ft_strlst_free(lst);
		free(str);
	}
}

void	sig_handler(int signum)
{
	if (get_t_vars()->in_readline)
	{
		if (signum == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			write_error_num(1);
		}
		else if (signum == SIGQUIT)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
	else
	{
		ft_putchar_fd('\n', 1);
		write_error_num((128 + signum));
		get_t_vars()->error_skip = true;
	}
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	t_vats_init(argv, envp);
	read_and_execute();
	if (argc && argv)
		exit(0);
}
