/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:24:48 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/30 19:04:17 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	1. Malloc mon tapis : ft_create_map
**	2. Malloc un tableau pouvant stocker des tableaux de 4 tableaux de 2 ints
**	(4 tableaux de 2 ints = 1 pièce)
**	3. Stocker par 4 tableaux de 2 ints
**	4. Coordonnées
**	printf(" coord j | coord i\n");
**	printf("j : %c  | i : %c\n", coord[k][sharp][0] + '0', coord[k]
**	[sharp][1] + '0');
*/

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
					sharp++;
				}
				i++;
			}
			j++;
		}
		k++;
	}
	return (0);
}

int			ft_preprocess(size_t i, char ***piece)
{
	size_t	j;
	size_t	k;
	char	***coord;

	j = 0;
	k = 0;
	coord = NULL;
	if (ft_create_coord(i, &coord) == 1)
		return (1);
	ft_get_pos(j, k, piece, coord);
	ft_up_left(coord);
	ft_print_coord(coord);
	return (0);
}
