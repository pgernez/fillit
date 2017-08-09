# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:37:56 by pgernez           #+#    #+#              #
#    Updated: 2017/08/09 16:47:17 by pgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = obj
SRC_PATH = srcs/fillit
OBJ_PATH = $(OBJ_DIR)/fillit
SRC_NAME = read_file.c\
		 validation.c\
		 preprocessing.c\
		 put_upper_left.c\
		 solver.c\
		 main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
LIBFT_PATH = srcs/libft/
LIB_DIR = lib/
LDFLAGS = -L$(LIB_DIR)
LDLIBS = -lft
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes/
DIR = $(OBJ_DIR) $(LIB_DIR) $(OBJ_PATH)
NAME = fillit

.PHONY: all clean fclean re
export LIB_DIR
export OBJ_DIR

all: $(DIR) $(NAME)

$(DIR):
	mkdir -p $@

$(NAME) : $(DIR) $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make -C $(LIBFT_PATH) $@
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) $(OBJ_DIR) 2> /dev/null || true

fclean:
	make -C $(LIBFT_PATH) $@
	rm -f $(OBJ)
	rm -f $(NAME)
	@rmdir $(OBJ_PATH) $(LIB_DIR) $(OBJ_DIR) 2> /dev/null || true

re: fclean all

norm:
	norminette $(SRC)
