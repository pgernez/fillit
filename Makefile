# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:37:56 by pgernez           #+#    #+#              #
#    Updated: 2017/08/04 16:43:07 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = lib/ft_putstr.c\
		 lib/ft_strlen.c\
		 lib/ft_memset.c\
		 lib/ft_memmove.c\
		 lib/ft_memcpy.c\
		 srcs/read_file.c\
		 srcs/validation.c\
		 srcs/preprocessing.c\
		 srcs/put_upper_left.c\
		 srcs/solver.c\
		 srcs/main.c\

SOURCE_O = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Wextra -Werror -I includes/ $(SOURCE)

%.o: %.c
	$(NAME)

clean:
	/bin/rm -f $(SOURCE_O)

fclean: clean
	/bin/rm $(NAME)

re: all fclean
