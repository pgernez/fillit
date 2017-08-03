/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:56:10 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/04 00:04:30 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

/*
**	ft_put_piece puts a piece on the map. It returns 1 in case of success and 0
**	if we cannot.
**	The first part of the function tells us if we can put a piece (the # are on
**	the map && do not cover another piece), the second part puts a piece.
**
**	nb : ft_can_put also converts # in letters according to their position in
**	the pieces list.
**	nb : ne pas calculer la taille de la map à chaque fois
**	ne pas envoyer avant la dernière pièce identique
**		printf("Current piece : %zu at %zu %zu\n", current->x, pt.x, pt.y);
**		fflush(stdout);
*/



static int	ft_put_piece(char **map, t_couple *pt, char **coord, size_t size)
{
	size_t	s;

	s = 0;
	while (s < 4)
	{
		if ((pt->x + coord[s][0]) >= size || (pt->y + coord[s][1]) >= size)
			return (0);
		if (map[pt->x + (size_t)coord[s][0]]
			[pt->y + (size_t)coord[s][1]] != '.')
			return (0);
		s++;
	}
	s = 0;
	while (s < 4)
	{
		map
		[pt->x + (size_t)coord[s][0]]
		[pt->y + (size_t)coord[s][1]] = coord[4][0];
		s++;
	}
	return (1);
}

/*
**	ft_remove removes a piece from the map. It returns 1 in case of success and
**	0 if we cannot.
*/

static int	ft_remove(char **map, t_couple *pt, char **coord)
{
	size_t	s;

	s = 0;
	while (s < 4)
	{
		map[pt->x + (size_t)coord[s][0]][pt->y + (size_t)coord[s][1]] = '.';
		s++;
	}
	return (1);
}

/*
**	ft_solve is a backtracking function solving our map. It returns 1 in
**	case of success and 0 if we cannot.
**	current->x stands for the current piece and current->y for the number of
**	pieces, so that current->x == current->y means we placed all the pieces.
**	The t_couple *pt stands for the piece couple of coordinates.
**	The t_couple *next_piece stands for the next_piece couple of coordinates.
*/

static int	ft_solve(char **map, char ***coord, t_couple *current, size_t size)
{
	t_couple	pt;
	t_couple	next_piece;

	pt.x = 0;
	if ((current->x) == (current->y))
		return (1);
	while (pt.x < size)
	{
		pt.y = 0;
		while (pt.y < size)
		{
			if (ft_put_piece(map, &pt, coord[current->x], size) == 1)
			{
				next_piece.x = current->x + 1;
				next_piece.y = current->y;
				if (ft_solve(map, coord, &next_piece, size) == 1)
					return (1);
				ft_remove(map, &pt, coord[current->x]);
			}
			pt.y++;
		}
		pt.x++;
	}
	return (0);
}

#include <string.h>

static int	ft_tab_copy(char **src, char ***dst, size_t size)
{
	size_t	i;

	i = 0;
	(*dst) = (char**)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		(*dst)[i] = (char *)malloc(sizeof(char) * (size + 1));
		memmove((*dst)[i], src[i], size + 1);
		i++;
	}
	(*dst)[i] = NULL;
	return (0);
}

int			ft_find_smallest_size(t_main *var, t_couple *current)
{
	size_t	size;
	char	**carpet;

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
	}
	return (0);
}
