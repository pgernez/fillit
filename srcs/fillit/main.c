/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/06 18:57:25 by vmatthys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_manage_arg(int argc)
{
	if (argc == 1)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
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

static int	ft_clean_tab(char ***tab)
{
	size_t	j;

	if (tab && *tab)
	{
		j = 0;
		while ((*tab)[j])
		{
			free((*tab)[j]);
			(*tab)[j] = NULL;
		}
		*tab = NULL;
	}
	return (1);
}

static int	ft_clean(char ****piece, char ***map, char ****coord)
{
	size_t	k;

	(void)piece;
	(void)map;
	(void)coord;
	if (*piece)
	{
		k = 0;
		while ((*piece)[k])
			ft_clean_tab(&(*piece)[k++]);
		free(*piece);
		*piece = NULL;
	}
	(void)map;
	ft_clean_tab(map);
	if (*coord)
	{
		k = 0;
		while ((*coord)[k])
			ft_clean_tab(&(*coord)[k++]);
		free(*coord);
		*coord = NULL;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_couple	current;
	t_main		var;

	current.x = 0;
	var.map = NULL;
	var.coord = NULL;
	var.piece = NULL;
	if (ft_manage_arg(argc) == 1)
		return (1);
	if (ft_open_read_close(argv, &var.piece) == 1)
		return (ft_clean(&var.piece, &var.map, &var.coord));
	if ((current.y = ft_input_check(var.piece)) > 26)
		return (ft_clean(&var.piece, &var.map, &var.coord));
	if ((var.coord = ft_preprocess(current.y, var.piece)) == NULL)
		return (ft_clean(&var.piece, &var.map, &var.coord));
	ft_find_smallest_size(&var, &current);
	current.x = 0;
	while (current.x < var.size)
	{
		ft_putstr(var.map[current.x++]);
		write(1, "\n", 1);
	}
	ft_clean(&var.piece, &var.map, &var.coord);
	return (0);
}
