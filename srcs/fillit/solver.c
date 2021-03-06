/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:56:10 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/08 14:59:14 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_put_piece puts a piece on the map. It returns 1 in case of success and 0
**	if we cannot.
**	The first part of the function tells us if we can put a piece (the # are on
**	the map && do not cover another piece), the second part puts a piece.
**	The 2 last lines stocks in the last lines of our table of coordinates the
**	position of the fresh dropped piece in the map.
*/

static int	ft_put_piece(char **map, t_couple pt, char **coord, size_t size)
{
	size_t	s;

	s = 0;
	while (s < 4)
	{
		if ((pt.x + coord[s][0]) >= size || (pt.y + coord[s][1]) >= size)
			return (0);
		if (map[pt.x + (size_t)coord[s][0]]
			[pt.y + (size_t)coord[s][1]] != '.')
			return (0);
		s++;
	}
	s = 0;
	while (s < 4)
	{
		map
		[pt.x + (size_t)coord[s][0]]
		[pt.y + (size_t)coord[s][1]] = coord[4][0];
		s++;
	}
	coord[6][0] = pt.x;
	coord[6][1] = pt.y;
	return (1);
}

/*
**	ft_remove removes a piece from the map, meaning replacing the letter by a
**	'.', and reinit coord[6] to 0. It returns 1 in case of success.
*/

static int	ft_remove(char **map, t_couple pt, char **coord)
{
	size_t	s;

	s = 0;
	while (s < 4)
	{
		map[pt.x + (size_t)coord[s][0]][pt.y + (size_t)coord[s][1]] = '.';
		s++;
	}
	coord[6][0] = 0;
	coord[6][1] = 0;
	return (1);
}

/*
**	ft_solve is a backtracking function solving our map. It returns 1 in
**	case of success and 0 if we cannot.
**	Current->x stands for the current piece and current->y for the number of
**	pieces, so that current->x == current->y means we placed all the pieces.
**	The t_couple *pt stands for the piece couple of coordinates.
**	The t_couple *next_piece stands for the next_piece couple of coordinates.
**	coord[current->x][5][0] = index of previous piece with the same pattern.
*/

static int	ft_solve(char **map, char ***coord, t_couple *current, size_t size)
{
	t_couple	pt;
	t_couple	next_piece;

	if ((current->x) == (current->y))
		return (1);
	pt.x = (size_t)coord[(size_t)coord[current->x][5][0]][6][0];
	pt.y = (size_t)coord[(size_t)coord[current->x][5][0]][6][1];
	while (pt.x < size)
	{
		while (pt.y < size)
		{
			if (ft_put_piece(map, pt, coord[current->x], size) == 1)
			{
				next_piece.x = current->x + 1;
				next_piece.y = current->y;
				if (ft_solve(map, coord, &next_piece, size) == 1)
					return (1);
				ft_remove(map, pt, coord[current->x]);
			}
			pt.y++;
		}
		pt.y = 0;
		pt.x++;
	}
	return (0);
}

/*
**	ft_tab_copy uses ft_memmove to make a copy of the solving map that will be
**	used if a solution is found (e.g. we copy carpet in map).
*/

static int	ft_tab_copy(char **src, char ***dst, size_t size)
{
	size_t	i;

	i = 0;
	(*dst) = (char**)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		(*dst)[i] = (char *)malloc(sizeof(char) * (size + 1));
		ft_memmove((*dst)[i], src[i], size + 1);
		i++;
	}
	(*dst)[i] = NULL;
	return (0);
}

/*
**	ft_find_smallest_size is a function managing the solving part of the
**	programme. The t_main structure is a batch of variables used in the main -
**	we use here the solving map and the table of the pieces coordinates. The
**	t_couple *current is a pointer pointing to a couple of size_t, where x
**	stands for our current piece and y stands for the total number of pieces.
**	Char **carpet is the map we try to solve.
**	It cleans the coord positions when a solution is found.
**	The function returns 0 in case of success and 1 otherwise.
*/

int			ft_find_smallest_size(t_main *var, t_couple *current)
{
	size_t	size;
	char	**carpet;
	size_t	k;

	size = 16;
	while (size)
	{
		if (ft_init_full_map(&carpet, size) == 1)
			return (1);
		current->x = 0;
		if (ft_solve(carpet, var->coord, current, size) == 1)
			ft_tab_copy(carpet, &var->map, size);
		else
			return (0);
		var->size = size;
		size--;
		k = 0;
		while ((var->coord)[k])
		{
			(var->coord)[k][6][0] = 0;
			(var->coord)[k][6][1] = 0;
			k++;
		}
	}
	return (0);
}
