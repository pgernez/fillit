# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 12:56:44 by pgernez           #+#    #+#              #
#    Updated: 2017/02/24 13:03:23 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SOURCE =

SOURCE_O = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(SOURCE.O)
	ar rc $(NAME) $(SOURCE_O)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $<

clean:
	/bin/rm -f $(SOURCE_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
