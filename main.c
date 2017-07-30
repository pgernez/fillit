/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/30 22:25:44 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	***piece;
	size_t	k;

	// size_t	n;
	if (argc == 1)
	{
		ft_putstr("File name missing\nusage: ./fillit tetriminos_file\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments\nusage: ./fillit tetriminos_file\n");
		return (0);
	}
	piece = NULL;
	if (ft_open_read_close(argv, &piece) == 1)
		return (1);
	if ((k = ft_input_check(piece)) > 26)
		return (1);
	// n = 4; + n dans ft_solve
	if (ft_preprocess(k, piece) == 1)
		return (1);
	if (ft_solve() == 0)
		return (1)
	ft_print_tetritab(piece);
	return (0);
}
