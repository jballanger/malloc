ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
#NAME = malloc
LIBFT = lft
SRC_NAME = main.c\
	malloc.c\
	realloc.c\
	free.c\
	page.c\
	header.c\
	block.c\
	show.c
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(SRC:.c=.o)
CC = clang
CPPFLAGS = -Iincludes
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

lft:
	$(MAKE) -C libft

$(NAME): $(OBJ)
	#$(CC) $^ -o $@  -Llibft -lft
	$(CC) -shared $^ -o $@  -Llibft -lft
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY : all, clean, fclean, re, lft
