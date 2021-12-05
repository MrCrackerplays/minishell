/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l_atoi.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 17:18:31 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 16:37:04 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_latoi(const char *nptr)
{
	long	num;
	long	mul;

	num = 0;
	mul = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		mul = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += *nptr - 48;
		nptr++;
	}
	return (num * mul);
}
