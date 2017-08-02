/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:56:10 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/02 20:13:11 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
*/

static int	ft_put_piece(char **map, t_couple *pt, char **cord, size_t size)
{
	size_t	s;

	s = 0;
	while (s < 4)
	{
		if ((pt->x + cord[s][0]) >= size || (pt->y + cord[s][1]) >= size)
			return (0);
		if (map[pt->x + (size_t)cord[s][0]][pt->y + (size_t)cord[s][1]] == '#')
			return (0);
		s++;
	}
	s = 0;
	while (s < 4)
	{
		map[pt->x + (size_t)cord[s][0]][pt->y + (size_t)cord[s][1]] = '#';
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

int			ft_solve(char **map, char ***coord, t_couple *current, size_t size)
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
		printf("Current piece : %zu at %zu %zu\n", current->x, pt.x, pt.y);
		fflush(stdout);
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
