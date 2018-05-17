# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <jballang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 15:18:22 by jballang          #+#    #+#              #
#    Updated: 2018/05/17 15:10:40 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = 	ft_atoi.c ft_lstdelone.c ft_memmove.c ft_strcat.c ft_strjoin.c ft_strnstr.c ft_bzero.c \
ft_lstiter.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strrchr.c \
ft_isalnum.c ft_lstmap.c ft_putchar.c ft_strclr.c ft_strlen.c ft_strsplit.c \
ft_isalpha.c ft_lstnew.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c \
ft_isascii.c ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c ft_strsub.c \
ft_isdigit.c ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c \
ft_isprint.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c ft_tolower.c \
ft_itoa.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c \
ft_lstadd.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c \
ft_lstdel.c ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c \
ft_intlen.c ft_wordlenc.c ft_strintlen.c ft_isupper.c ft_islower.c ft_lstpush.c \
ft_rrange.c ft_isvalid.c ft_print_itoa_base.c ft_intlen_base.c

OBJ = $(SRC:.c=.o)

CPPFLAGS = -Iincludes
CC = clang
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all