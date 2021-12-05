/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_str.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 17:56:13 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/23 17:56:41 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_STR_H
# define ARR_STR_H

# include "../libft.h"

size_t		ft_strarr_len(char **arr);
char		**ft_strarr_copy(char **arr);
void		ft_strarr_free(char	**arr);

void		ft_strarr_print(char **arr);
void		ft_strarr_print_c(char **arr, char c);
void		ft_strarr_print_s(char **arr, char *s);

#endif
