/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:32:35 by pgernez           #+#    #+#             */
/*   Updated: 2017/03/12 19:30:19 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE 100

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		read_file(char **argv);

/* Rajouter les prototypes */

#endif
