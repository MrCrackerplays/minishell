NAME := minishell

CFLAGS ?= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif
SUB_OBJ_DIR := obj/pipex obj/pipex/builtins obj/pipex/utils
OBJECTS := minishell.o line_parser.o quote_handler.o \
	pipex/init.o \
	pipex/io.o \
	pipex/pipex.o \
	pipex/run.o \
	pipex/builtins/echo.o \
	pipex/builtins/cd.o \
	pipex/builtins/pwd.o \
	pipex/builtins/export.o \
	pipex/builtins/unset.o \
	pipex/builtins/env.o \
	pipex/builtins/assign.o \
	pipex/utils/exec.o \
	pipex/utils/get_arg.o \
	pipex/utils/heredoc.o \
	pipex/utils/pipe_close.o \
	pipex/utils/vars.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
INCLUDE := headers libft
INCLUDE := $(addprefix -I,$(INCLUDE))
HEADER_FILES := line_parser.h quote_handler.h pipex.h
HEADER_FILES := $(addprefix headers/,$(HEADER_FILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJECTS) -lreadline libft/libft.a -o $(NAME)

obj/%.o: src/%.c $(HEADER_FILES) obj
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

obj:
	@mkdir obj $(SUB_OBJ_DIR)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJECTS)
	@rm -rf obj

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

bonus: all

run: all
	./$(NAME)

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run debug
