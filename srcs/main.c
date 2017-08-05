/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/05 19:39:16 by pgernez          ###   ########.fr       */
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
**	ft_init_full_map initializes the map and allocates memory for
**	the final map to solve. It returns 1 if the allocations fails and 0 in case
**	of success.
*/

int			ft_init_full_map(char ***map, size_t size)
{
	size_t	line;

	if (!((*map) = (malloc(sizeof(char*) * (size + 1)))))
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
	t_couple	current;
	t_main		var;

	current.x = 0;
	var.size = 30;
	var.map = NULL;
	var.coord = NULL;
	if (ft_manage_arg(argc) == 1)
		return (1);
	if (ft_open_read_close(argv, &var.piece) == 1)
		return (1);
	if ((current.y = ft_input_check(var.piece)) > 26)
		return (1);
	if ((var.coord = ft_preprocess(current.y, var.piece)) == NULL)
		return (1);
	ft_find_smallest_size(&var, &current);
	current.x = 0;
	while (current.x < var.size)
	{
		ft_putstr(var.map[current.x++]);
		write(1, "\n", 1);
	}
	return (0);
}
