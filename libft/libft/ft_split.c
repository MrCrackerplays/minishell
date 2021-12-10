/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 17:18:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:38:17 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	arrlen(char const *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (i > 0)
				len++;
			i = 0;
		}
		else
			i++;
		s++;
	}
	return (len);
}

static char	*get_word(char *s, int n)
{
	char	*string;
	int		i;

	string = (char *) ft_malloc_e(sizeof(char) * (n + 2), "libft");
	ft_bzero(string, sizeof(char) * (n + 2));
	i = 0;
	while (i < n)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static int	assign_to_list(char **arr, int arr_i, int i, char *word_b)
{
	if (i > 0)
	{
		arr[arr_i] = get_word(word_b, i);
		arr_i++;
	}
	return (arr_i);
}

static void	get_arr(char **arr, char const *s, char c)
{
	char	*word_b;
	int		arr_i;
	int		i;

	word_b = (char *) s;
	arr_i = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			arr_i = assign_to_list(arr, arr_i, i, word_b);
			i = 0;
			word_b = (char *) s + 1;
		}
		else
			i++;
		s++;
	}
	arr_i = assign_to_list(arr, arr_i, i, word_b);
	arr[arr_i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		len;

	if (!s)
		return (NULL);
	len = sizeof(char *) * (arrlen(s, c) + 2);
	if (len == 0)
		return (NULL);
	arr = (char **) ft_malloc_e(len, "libft");
	get_arr(arr, s, c);
	return (arr);
}
