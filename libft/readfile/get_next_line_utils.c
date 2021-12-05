/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:04:55 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/12 20:18:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*m_strdup_plus(char	*s, int size)
{
	char	*d;
	int		i;

	if (!s)
	{
		d = malloc(2 * sizeof(char));
		if (!d)
			return (NULL);
		d[0] = '\0';
		d[1] = '\0';
		return (d);
	}
	d = malloc((size) * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void	m_strwrt(char *d, char *s)
{
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
}

void	m_strcat_n(char **s1, int *l1, char *s2, int l2)
{
	char	*str;
	int		i;

	if (!*s1 || !s2 || l2 == 0)
		return ;
	str = m_strdup_plus(*s1, *l1 + l2 + 1);
	if (*s1)
		free(*s1);
	if (!str)
	{
		*s1 = NULL;
		*l1 = 0;
		return ;
	}
	i = 0;
	while (i < l2)
	{
		str[*l1 + i] = s2[i];
		i++;
	}
	str[*l1 + i] = '\0';
	*l1 += l2;
	*s1 = str;
}

int	ft_line_len(char *file, int line)
{
	int	len;

	if (!file || *file == '\0')
		return (0);
	len = 1;
	while (*file)
	{
		if (*file == '\n')
		{
			if (line == 0)
				return (len);
			line--;
			len = -1;
		}
		file++;
		len++;
	}
	if (line == 0)
		return (len);
	return (0);
}

int	ft_lines(char *file)
{
	int	len;

	if (!file || *file == '\0')
		return (0);
	len = 1;
	while (*file)
	{
		if (*file == '\n')
			len++;
		file++;
	}
	return (len);
}
