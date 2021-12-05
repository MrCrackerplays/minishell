# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rdrazsky <rdrazsky@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/04 13:52:48 by rdrazsky      #+#    #+#                  #
#    Updated: 2021/12/03 19:39:36 by rdrazsky      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
HEADER = libft.h readfile/get_next_line.h tree_n_dictionary/tree_n_dict.h
LIBFT_FILES = \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_strlen \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memcmp \
	ft_memmove \
	ft_strlcpy \
	ft_strlcat \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_memchr \
	ft_strnstr \
	ft_atoi \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd
LIBFT_NEW_FILES = \
	ft_strcat \
	ft_latoi \
	ft_freear \
	ft_exit_error
PRINTF_FILES = \
	ft_printf \
	ft_print \
	ft_c \
	ft_s \
	ft_a \
	ft_x \
	ft_p \
	ft_b \
	ft_l \
	ft_i
READFILE_FILES = \
	get_next_line \
	get_next_line_utils \
	readfile
LIST_FILES = \
	list_find \
	list_info \
	list_manage \
	list_mem \
	list_map \
	list_iter
STR_LIST_FILES = \
	str_list_find \
	str_list_info \
	str_list_iter \
	str_list_manage \
	str_list_mem
INT_LIST_FILES = \
	int_list_find \
	int_list_info \
	int_list_manage \
	int_list_math \
	int_list_mem
STR_ARR_FILES = \
	ft_strarr_copy \
	ft_strarr_free \
	ft_strarr_print \
	ft_strarr_len
TREE_FILES = \
	tree \
	key_hash \
	dictionary
MATH_FILES = \
	abs
FREE_FILES = \
	free
STRING_FILES = \
	string_free \
	string_new \
	string_copy \
	string_edit \
	string_split \
	string_cut \
	string_insert \
	string_new
OBJ_DIR = obj
SRC = \
	$(foreach i, $(LIBFT_FILES), libft/$(i).c) \
	$(foreach i, $(LIBFT_NEW_FILES), libft_new/$(i).c) \
	$(foreach i, $(PRINTF_FILES), printf/$(i).c) \
	$(foreach i, $(READFILE_FILES), readfile/$(i).c) \
	$(foreach i, $(INT_LIST_FILES), list_int/$(i).c) \
	$(foreach i, $(STR_LIST_FILES), list_str/$(i).c) \
	$(foreach i, $(LIST_FILES), list/$(i).c) \
	$(foreach i, $(STR_ARR_FILES), arr_str/$(i).c) \
	$(foreach i, $(TREE_FILES), tree_n_dictionary/$(i).c) \
	$(foreach i, $(MATH_FILES), math/$(i).c) \
	$(foreach i, $(STRING_FILES), string/$(i).c) \
	$(foreach i, $(FREE_FILES), free/$(i).c)
OBJ = \
	$(foreach i, $(LIBFT_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(LIBFT_NEW_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(PRINTF_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(READFILE_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(INT_LIST_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(STR_LIST_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(LIST_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(STR_ARR_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(TREE_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(MATH_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(STRING_FILES), $(OBJ_DIR)/$(i).o) \
	$(foreach i, $(FREE_FILES), $(OBJ_DIR)/$(i).o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: */%.c | $(OBJ_DIR)
	gcc $(DEBUG) $(FLAG) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette

.PHONY: all clean fclean re dall norm
