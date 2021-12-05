/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_list_str.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 19:32:22 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 19:38:17 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_STR_H
# define S_LIST_STR_H

# include "../libft.h"

typedef struct s_strlist
{
	t_string				*str;
	struct s_strlist		*next;
}	t_strlist;

#endif
