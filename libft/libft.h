/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 17:30:50 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/12/10 13:36:09 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef BOOL
#  define BOOL int
#  define TRUE 1
#  define FALSE 0
# endif

// -~{ STRUCTS }~- //

# include "string/s_string.h"
# include "list_str/s_list_str.h"

// -~{ FREE }~- //

# include "free/free.h"

// -~{ STRING }~- //

# include "string/string.h"

// -~{ MATH }~- //

# include "math/math.h"

// -~{ LIST }~- //

# include "list/list.h"

// -~{ INT LIST }~- //

# include "list_int/int_list.h"

// -~{ STR LIST }~- //

# include "list_str/list_str.h"

// -~{ STR ARR }~- //

# include "arr_str/arr_str.h"

// -~{ TREE & DICTIONARY }~- //

# include "tree_n_dictionary/tree_n_dict.h"

// -~{ READ FILE }~- //

char		*ft_get_next_line(int fd);
int			ft_line_len(char *file, int line);
int			ft_lines(char *file);

char		*ft_readfile(int fd);
void		ft_writefile(char *name, char *text);
void		ft_writefile_ms(char *name, t_string *str);
void		ft_addfile(char *name, char *text);
void		ft_addfile_ms(char *name, t_string *str);

int			ft_tmp_open(char *name, int mode);

char		*ft_tmp_read(char *name);
void		ft_tmp_write(char *name, char *text);
void		ft_tmp_write_ms(char *name, t_string *str);
void		ft_tmp_add(char *name, char *text);
void		ft_tmp_add_ms(char *name, t_string *str);

// -~{ PRINTF }~- //

int			ft_print(const char *s, void *item);
int			ft_printf(const char *s, ...);

// -~{ LIBFT NEW }~- //

long		ft_latoi(const char *nptr);
char		*ft_strcat(char *d, char *s);

void		ft_exit_error(char *error);
void		ft_exit_error_n(char *error, int error_no);

void		*ft_malloc(size_t size);
void		*ft_malloc_e(size_t size, char *error);

// -~{ LIBFT }~- //

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);

size_t		ft_strlen(const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *d, const char *s, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
char		*ft_strdup(const char *s);

void		*ft_memset(void *src, int c, size_t n);
void		ft_bzero(void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

char		**ft_split(char const *s, char c);

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

char		*ft_substr(char const *s, unsigned int start, int len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
