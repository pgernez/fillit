# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/13 22:52:51 by pgernez           #+#    #+#              #
#    Updated: 2017/08/09 16:44:07 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RELATIVE = ../..
OBJ_PATH =  $(RELATIVE)/obj/libft
SRC_NAME =	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = $(RELATIVE)/includes/
LIBFT_PATH = $(RELATIVE)/$(LIB_DIR)
CPPFLAGS = -I$(INC)
DIR = $(OBJ_PATH)
NAME = $(LIBFT_PATH)/libft.a

.PHONY: clean fclean all re

all: $(DIR) $(NAME)

$(DIR):
	mkdir -p $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)%.c $(INC)libft.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@rmdir $(DIR) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all
