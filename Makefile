ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LIBFT = lft
SRC_NAME = malloc.c\
	realloc.c\
	free.c\
	page.c\
	header.c\
	block.c\
	show.c\
	search.c\
	checksum.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
CC = clang
CPPFLAGS = -Iincludes
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

lft:
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) -lpthread -shared $^ -o $@  -Llibft -lft
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY : all, clean, fclean, re, lft
