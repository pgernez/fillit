/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:32:35 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/30 19:02:20 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	ATTENTION NETTOYER LES INCLUDES DE .h
*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

void	ft_putstr(char *str);
int		ft_open_read_close(char **argv, char ****new);
size_t	ft_input_check(char ***tab);
int		ft_preprocess(size_t k, char ***piece);
int		ft_up_left(char ***coord);
void	ft_print_coord(char ***coord);
void	ft_print_tetritab(char ***tab);
size_t	ft_strlen(char *str);

#endif
