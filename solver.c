/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:56:10 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/31 19:16:17 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ft_can_put also converts # in letters according to their position in the pieces list.

/*
**	ft_init_carpet initializes the carpet structure and allocates memory for
**	the final map to solve. It returns 1 if the allocations fails and 0 in case
**	of success.
*/

static int	ft_init_full_map(char **map, size_t x, size_t y, size_t n)
{
	size_t	line;

	x = 0;
	y = 0;
	if (!((*map) = (char**)malloc(sizeof(char*) * (n + 1))))
		return (1);
	line = 0;
	while (line < n)
	{
		if (!((*map)[line] = (char*)malloc(sizeof(char) * (n + 1))))
			return (1);
		line++;
	}
	return (0);
}

/*
**	ft_can_put checks for a given piece whether we can put a piece on the map
**	or not. It returns 1 in case of success and 0 if we cannot.
*/

static int	ft_can_put(char **map, size_t x, size_t y, char **coord)
{
}

/*
**	ft_put_piece puts a piece on the map. It returns 1 in case of success and 0
**	if we cannot.
*/

static int	ft_put_piece(char **map, size_t x, size_t y, char **coord)
{
	return (1);
}

/*
**	ft_remove removes a piece from the map. It returns 1 in case of success and
**	0 if we cannot.
*/

static int	ft_remove(char **map, size_t x, size_t y, char **coord)
{
	return (1);
}

static int	ft_solve(char **map, size_t x, size_t y, char ***coord, size_t current, size_t nb_piece)
{
	if (current == nb_piece)
		return (1);  // J'ai réussi à tout placer
	if (ft_init_full_map(map, x, y, nb_piece) == 1)
		return (1);
	if (ft_can_put(map, x, y, coord[k]) == 1)
	{
		ft_put_piece(map, x, y, coord[k]);
		if (ft_solve(map, x, y, coord[k], current + 1, nb_piece) == 1)
			return (1);
		ft_remove(map, x, y, coord[k]);
	}
	return (0);
}
