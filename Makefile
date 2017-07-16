# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:37:56 by pgernez           #+#    #+#              #
#    Updated: 2017/03/12 19:35:56 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE = ft_putstr.c\
		 read_file.c\
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
