/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hash.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 12:14:06 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 12:14:06 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned long	get_hashed_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 26);
	if (c >= '0' && c <= '9')
		return (c - 'A' + 52);
	if (c == '.')
		return (62);
	if (c == '_')
		return (63);
	return (0);
}

unsigned long	ft_dict_hash(char *str)
{
	unsigned long	key;
	int				i;

	if (ft_strlen(str) > 12)
		return (0);
	key = 0;
	i = 0;
	while (str[i])
	{
		key += get_hashed_letter(str[i]) << 5 * i;
		i++;
	}
	return (key);
}

static char	get_unhashed_letter(unsigned long n)
{
	if (n >= 0 && n <= 25)
		return (n + 'a');
	if (n >= 26 && n <= 51)
		return (n + 'A' - 26);
	if (n >= 52 && n <= 61)
		return (n + '0' - 52);
	if (n == 62)
		return ('.');
	if (n == 63)
		return ('_');
	return (0);
}

void	ft_dict_hash_print(unsigned long key)
{
	while (key)
	{
		ft_printf("%c", get_unhashed_letter(key & 31));
		key = key >> 5;
	}
}
