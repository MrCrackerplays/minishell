/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_list.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 17:15:52 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/08 18:13:21 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_LIST_H
# define INT_LIST_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BOOL
#  define BOOL int
#  define TRUE 1
#  define FALSE 0
# endif

typedef struct s_intlist
{
	long				value;
	struct s_intlist	*next;
}	t_intlist;

// -~{ Find }~- //
t_intlist		*ft_intlst_find(t_intlist *lst, int value);
int				ft_intlst_find_indx(t_intlist *lst, int value);
t_intlist		*ft_intlst_last(t_intlist *lst);
t_intlist		*ft_intlst_find_max(t_intlist *lst);
t_intlist		*ft_intlst_find_min(t_intlist *lst);

// -~{ Math }~- //
void			ft_intlst_add_all(t_intlist *lst, int value);
void			ft_intlst_mult_all(t_intlist *lst, int value);
int				ft_intlst_sum(t_intlist *lst);

// -~{ Manage }~- //
void			ft_intlst_add_back(t_intlist **lst, t_intlist *new);
void			ft_intlst_add_front(t_intlist **lst, t_intlist *new);
void			ft_intlst_remove(t_intlist **lst, t_intlist *element);

// -~{ Info }~- //
int				ft_intlst_size(t_intlist *lst);
BOOL			ft_intlst_is_sorted(t_intlist *lst);

// -~{ Memmory }~- //
t_intlist		*ft_intlst_new(int value);
t_intlist		*ft_intlst_copy(t_intlist *og_lst);
void			ft_intlst_free(t_intlist *lst);
t_intlist		*ft_intlst_arg2list(int argc, char **argv);

#endif
