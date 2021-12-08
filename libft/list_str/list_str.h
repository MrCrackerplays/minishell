/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_str.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 17:04:46 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/07 12:36:08 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STR_H
# define LIST_STR_H

# include "../libft.h"

t_strlist		*ft_strlst_new(t_string *text);
void			ft_strlst_add_back(t_strlist **lst, t_strlist *new);
void			ft_strlst_add_front(t_strlist **lst, t_strlist *new);
int				ft_strlst_size(t_strlist *lst);
t_strlist		*ft_strlst_last(t_strlist *lst);
void			ft_strlst_free(t_strlist *lst);
void			ft_strlst_iter(t_strlist *lst, void (*f)(t_string *));

char			**ft_strlst_to_arr(t_strlist *lst);

t_strlist		*ft_strlst_copy(t_strlist *lst);
void			ft_strlst_remove(t_strlist **lst, t_strlist *element);
void			ft_strlst_remove_free(t_strlist **lst, t_strlist *element);
void			ft_strlst_print(t_strlist *lst);
void			ft_strlst_print_c(t_strlist *lst, char c);
void			ft_strlst_print_s(t_strlist *lst, char *s);

#endif
