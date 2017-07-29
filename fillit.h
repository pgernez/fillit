/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:32:35 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/16 19:06:50 by pgernez          ###   ########.fr       */
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
int		ft_input_check(char ***tetritab);
int		ft_solve(char ***piece);
void	ft_print_tetritab(char ***tab);
size_t	ft_strlen(char *str);

#endif
