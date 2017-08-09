/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:32:35 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/09 16:14:36 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct		s_couple
{
	size_t			x;
	size_t			y;
}					t_couple;

typedef struct		s_main
{
	char			***piece;
	char			**map;
	char			***coord;
	size_t			size;
}					t_main;

int					ft_open_read_close(char **argv, char ****new);
size_t				ft_input_check(char ***tab);
char				***ft_preprocess(size_t k, char ***piece);
int					ft_up_left(char ***coord);
void				ft_print_coord(char ***coord);
int					ft_init_full_map(char ***map, size_t size);
int					ft_find_smallest_size(t_main *var, t_couple *current);

#endif
