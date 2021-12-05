/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_string.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 19:31:08 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 20:18:19 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STRING_H
# define S_STRING_H

# include "../libft.h"

typedef struct s_string {
	char	*text;
	size_t	len;
}	t_string;

#endif
