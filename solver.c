/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 10:53:41 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/25 17:16:23 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	1. Malloc mon tapis : ft_create_map
**	2. Malloc un tableau pouvant stocker des tableaux de 4 tableaux de 2 ints
**	(4 tableaux de 2 ints = 1 pièce)
**	3. Stocker par 4 tableaux de 2 ints
**	4. Coordonnées
*/

// static char	**ft_create_map(size_t n)
// {
// 	char	**map;
// 	size_t	line;
//
// 	if (!(map = (char**)malloc(sizeof(char*) * (n + 1))))
// 		return (1);
// 	line = 0;
// 	while (line < n)
// 	{
// 		if (!(map[line] = (char*)malloc(sizeof(char) * (n + 1))))
// 			return (1);
// 		line++;
// 	}
// 	return (map);
// }

static int	ft_create_coord(size_t nb_piece, char ****coord)
{
	size_t	j;
	size_t	k;

	k = 0;
	if (!((*coord) = (char***)malloc(sizeof(char**) * (nb_piece + 1))))
		return (1);
	while (k < nb_piece)
	{
		j = 0;
		if (!((*coord)[k] = (char**)malloc(sizeof(char*) * 4)))
			return (1);
		while (j < 4)
		{
			if (!((*coord)[k][j] = (char*)malloc(sizeof(char) * 2)))
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

static int	ft_get_pos(size_t j, size_t k, char ***tab, char ***coord)
{
	size_t	i;
	size_t	sharp;

	while (tab[k] != NULL)
	{
		sharp = 0;
		j = 0;
		while (tab[k][j] != 0)
		{
			i = 0;
			while (tab[k][j][i] != 0)
			{
				if (tab[k][j][i] == '#')
				{
					coord[k][sharp][0] = (char)j;
					coord[k][sharp][1] = (char)i;
					printf("k : %zu -- j : %zu -- i : %zu\n", k, j, i);
					sharp++;
					i++;
				}
			}
			j++;
		}
		k++;
	}
	return (0);
}

// size_t n dans ft_solve,

int	ft_solve(char ***piece)
{
	size_t	j;
	size_t	k;
	char	***coord;
	size_t	nb_piece;

	j = 0;
	k = 0;
	nb_piece = 26;
	coord = NULL;
	// if (ft_create_map(n) == 1)
	// 	return (1);
	if (ft_create_coord(nb_piece, &coord) == 1)
		return (1);
	ft_get_pos(j, k, piece, coord);
	return (0);
}
