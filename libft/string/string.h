/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 16:29:48 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/20 16:29:48 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "../libft.h"

t_string	*ft_str_new(char *src);
t_string	*ft_str_new_l(char *src, size_t len);

t_string	*ft_str_copy(t_string *str);
void		ft_str_copy_to(t_string *des, t_string *src);
void		ft_str_free(t_string *str);
t_strlist	*ft_str_split(char *s, char c);
char		*ft_str_strip(t_string *str);

void		ft_str_write_d(char *des, char *src, size_t len);
void		ft_str_cat(t_string *des, t_string *src);

void		ft_str_insert(t_string *d, t_string *s, size_t index);
void		ft_str_insert_s(t_string *d, char *s, size_t index);

t_string	*ft_str_cut(t_string *str, size_t start, size_t len);
t_string	*ft_str_cut_out(t_string *str, size_t start, size_t len);

void		ft_str_patch_to(t_string *des, t_string *src);

#endif
