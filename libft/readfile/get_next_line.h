/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:04:58 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 16:26:37 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_readfile(int fd);
char	*ft_get_next_line(int fd);

char	*m_strdup_plus(char	*s, int add);
void	m_strwrt(char *d, char *s);
void	m_strcat_n(char **s1, int *l1, char *s2, int l2);

typedef struct s_read_block
{
	char	buff[BUFFER_SIZE + 1];
	int		is_end;
	int		fd;
	int		ret;
}	t_read_block;

#endif
