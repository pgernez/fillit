/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:56:10 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/05 18:57:20 by pgernez          ###   ########.fr       */
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
**	ft_remove removes a piece from the map, meaning replacing the letter by a
**	'.'. It returns 1 in case of success.
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
**	Current->x stands for the current piece and current->y for the number of
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

/*
**	ft_tab_copy uses ft_memmove to make a copy of the solving map that will be
**	used if a solution is found.
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
**	Char **carpet is the definitive map.
**	The function returns 0 in case of success and 1 if not.
*/

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
