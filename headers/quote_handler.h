/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_handler.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:23:17 by pdruart       #+#    #+#                 */
/*   Updated: 2021/12/07 13:36:37 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_HANDLER_H
# define QUOTE_HANDLER_H
# include <libft.h>

t_string	*quote_handling(t_string *cut);
t_string	*quote_handling_free(t_string *cut);

#endif