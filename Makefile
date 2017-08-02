# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:37:56 by pgernez           #+#    #+#              #
#    Updated: 2017/08/02 15:27:09 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = ft_putstr.c\
		 ft_strlen.c\
		 ft_memset.c\
		 read_file.c\
		 validation.c\
		 preprocessing.c\
		 put_upper_left.c\
		 solver.c\
		 print_table.c\
		 main.c

SOURCE_O = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Wextra -Werror $(SOURCE)

%.o: %.c
	$(NAME)

clean:
	/bin/rm -f $(SOURCE_O)

fclean: clean
	/bin/rm $(NAME)

re: all fclean
