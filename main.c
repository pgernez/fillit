/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/01 23:31:04 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_init_carpet initializes the carpet structure and allocates memory for
**	the final map to solve. It returns 1 if the allocations fails and 0 in case
**	of success.
*/

int	ft_init_full_map(char ***map, size_t size)
{
	size_t	line;

	if (!((*map) = (char**)malloc(sizeof(char*) * (size + 1))))
		return (1);
	line = 0;
	while (line < size)
	{
		if (!((*map)[line] = (char*)malloc(sizeof(char) * (size + 1))))
			return (1);
		ft_memset((void*)(*map)[line], '.', size);
		(*map)[line][size] = 0;
		line++;
	}
	(*map)[line] = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	char	***piece;
	size_t	k;

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
	if (ft_preprocess(k, piece) == 1)
		return (1);
	if (ft_init_full_map(map, size) == 1)
		return (1);
	if (ft_solve(, k) == 0)
		return (1);
	ft_print_tetritab(piece);
	return (0);
}
