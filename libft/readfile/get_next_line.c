/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:04:57 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 16:26:04 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

static void	get_next_block(t_read_block *block, int fd)
{
	int	ret;

	block->buff[0] = '\0';
	ret = read(fd, block->buff, BUFFER_SIZE);
	if (ret == -1)
	{
		block->buff[0] = '\0';
		block->is_end = 1;
		return ;
	}
	block->buff[ret] = '\0';
	block->is_end = ret < BUFFER_SIZE;
}

static void	*free_and_return_null(char *line)
{
	free(line);
	return (NULL);
}

static char	*parser(t_read_block *block, int fd, char *line, int len)
{
	int	i;

	while (1)
	{
		i = 0;
		while (block->buff[i])
		{
			if (block->buff[i] == '\n')
			{
				m_strcat_n(&line, &len, block->buff, i + 1);
				m_strwrt(&block->buff[0], &block->buff[i + 1]);
				return (line);
			}
			i++;
		}
		m_strcat_n(&line, &len, block->buff, i);
		if (block->is_end)
		{
			block->buff[0] = '\0';
			if (!line || line[0] == '\0')
				return (free_and_return_null(line));
			return (line);
		}
		get_next_block(block, fd);
	}
}

char	*ft_get_next_line(int fd)
{
	static t_read_block	block;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!block.buff[0] || block.fd != fd)
	{
		block.is_end = 0;
		block.fd = fd;
		get_next_block(&block, fd);
	}
	if (block.is_end && block.buff[0] == '\0')
		return (NULL);
	return (parser(&block, fd, m_strdup_plus("", 2), 0));
}

// char	*ft_readfile(int fd)
// {
// 	char	*file;
// 	char	*line;
// 	char	*tmp;

// 	file = ft_get_next_line(fd);
// 	if (!file)
// 		return (NULL);
// 	line = ft_get_next_line(fd);
// 	while (line)
// 	{
// 		tmp = ft_strcat(file, line);
// 		free(file);
// 		free(line);
// 		file = tmp;
// 		line = ft_get_next_line(fd);
// 	}
// 	return (file);
// }
