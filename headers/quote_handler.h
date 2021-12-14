/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_handler.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:23:17 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/13 19:33:05 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_HANDLER_H
# define QUOTE_HANDLER_H
# include <libft.h>

t_string	*quote_handling(t_string *cut);
t_string	*quote_handling_free(t_string *cut);

t_string	*quote_handling_free2(t_string *str);

#endif