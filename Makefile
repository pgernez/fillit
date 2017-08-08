# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:37:56 by pgernez           #+#    #+#              #
#    Updated: 2017/08/07 12:43:57 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

SRC_PATH = srcs

SRC_NAME = ft_putstr.c\
		 ft_memset.c\
		 ft_memmove.c\
		 ft_memcpy.c\
		 ft_strncmp.c\
		 read_file.c\
		 validation.c\
		 preprocessing.c\
		 put_upper_left.c\
		 solver.c\
		 main.c\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Werror -Wall -Wextra

CPPFLAGS = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC)
