NAME := minishell

CFLAGS ?= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS := -g $(CFLAGS)
endif
OBJECTS := minishell.o
OBJECTS := $(addprefix obj/,$(OBJECTS))
INCLUDE := headers
INCLUDE := $(addprefix -I,$(INCLUDE))
HEADER_FILES := 
HEADER_FILES := $(addprefix headers/,$(HEADER_FILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

obj/%.o: src/%.c $(HEADER_FILES)
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

run: all
	./$(NAME)

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re bonus run debug
