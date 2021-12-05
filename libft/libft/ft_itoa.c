/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 11:00:40 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/05 15:12:52 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Put character at end of string and NULL terminate it
static void	strjoinchr(char *s, char c)
{
	while (*s)
		s++;
	*s = c;
	s++;
	*s = '\0';
}

// Put number into string (assumes the string has enough space)
static void	putnbr_itoa(char *s, int n)
{
	long	nb;

	nb = (long) n;
	if (nb < 0)
	{
		strjoinchr(s, '-');
		nb *= -1;
	}
	if (nb > 9)
		putnbr_itoa(s, nb / 10);
	nb = nb % 10 + '0';
	strjoinchr(s, nb);
}

// Convert int to string
char	*ft_itoa(int n)
{
	int		len;
	int		og_n;
	char	*string;

	og_n = n;
	len = 2;
	while (n)
	{
		len++;
		n /= 10;
	}
	string = (char *) malloc(sizeof(char) * len);
	if (!string)
		return (NULL);
	ft_bzero(string, sizeof(char) * len);
	putnbr_itoa(string, og_n);
	return (string);
}
