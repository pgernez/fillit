# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:37:56 by pgernez           #+#    #+#              #
#    Updated: 2017/08/06 17:08:53 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = lib/ft_putstr.c\
		 lib/ft_memset.c\
		 lib/ft_memmove.c\
		 lib/ft_memcpy.c\
		 lib/ft_strncmp.c\
		 srcs/read_file.c\
		 srcs/validation.c\
		 srcs/preprocessing.c\
		 srcs/put_upper_left.c\
		 srcs/solver.c\
		 srcs/main.c\

OBJ_NAME = $(SOURCE:.c=.o)

CFLAGS = -Werror -Wall -Wextra

CPPFLAGS = -Iinclude

all: $(NAME)

$(NAME): $(OBJ_NAME)
	gcc  $(OBJ_NAME) -o $@

%.o: %.c
	gcc $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ_NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
