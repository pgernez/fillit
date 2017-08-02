/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/02 19:58:18 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_manage_arg(int argc)
{
	if (argc == 1)
	{
		ft_putstr("File name missing\nusage: ./fillit tetriminos_file\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments\nusage: ./fillit tetriminos_file\n");
		return (1);
	}
	return (0);
}

/*
**	ft_init_carpet initializes the carpet structure and allocates memory for
**	the final map to solve. It returns 1 if the allocations fails and 0 in case
**	of success.
*/

int			ft_init_full_map(char ***map, size_t size)
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

int			main(int argc, char **argv)
{
	size_t		k;
	t_couple	current;
	// t_main		var;
	char		***piece;
	char		**map;
	char		***coord;
	size_t		size;

	ft_putstr("0. Coucou\n");
	//current = NULL;
	map = NULL;
	size = 5;
	coord = NULL;
	// var->map = 0;
	// var->size = 26;
	ft_putstr("0 bis. Coucou\n");
	if (ft_manage_arg(argc) == 1)
		return (1);
	// var->piece = NULL;
	// open read_file prend (argv, &piece)
	// var->piece = NULL;
	if (ft_open_read_close(argv, &piece) == 1)
		return (1);
	ft_putstr("1. Coucou\n");
	if ((k = ft_input_check(piece)) > 26)
		return (1);
	ft_putstr("2. Coucou\n");
	if ((coord = ft_preprocess(k, piece)) == NULL)
		return (1);
	ft_putstr("3. Coucou\n");
	if (ft_init_full_map(&map, size) == 1)
		return (1);
	ft_putstr("4. Coucou\n");
	current.x = 0;
	current.y = k;
	if (ft_solve(map, coord, &current, size) == 0)
		return (1);
	printf("J'ai trouvé une solution\n");
	k = 0;
	while (k < size)
	{
		ft_putstr(map[k++]);
		write(1, "\n", 1);
	}
	ft_print_tetritab(piece);
	return (0);
}
