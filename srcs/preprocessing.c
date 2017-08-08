/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:24:48 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/08 14:53:39 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_create_coord allocates memory for the tables of coordinates. The 5th
**	line aims at stocking the letter, allowing us to use it
**	later for the solving part. It returns 1 if the allocation fails and 0
**	otherwise.
**	coord[k][0 - 3] = coordinates of #
**	coord[k][4][0] = letter
**	coord[k][5][0] = index of the previous same piece
**	coord[k][6] = position of the current piece (coord[k][6][0 / 1] = x / y)
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
		if (!((*coord)[k] = (char**)malloc(sizeof(char*) * 7)))
			return (1);
		while (j < 7)
		{
			if (!((*coord)[k][j] = (char*)malloc(sizeof(char) * 2)))
				return (1);
			j++;
		}
		(*coord)[k][4][0] = 'A' + k;
		(*coord)[k][5][0] = (char)k;
		(*coord)[k][6][0] = 0;
		(*coord)[k][6][1] = 0;
		k++;
	}
	return (0);
}

/*
**	ft_get_pos stocks couples of coordinates in coord.
*/

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

static int	ft_piececmp(char **coord1, char **coord2)
{
	size_t	sharp;

	sharp = 0;
	while (sharp < 4)
	{
		if (ft_strncmp(coord1[sharp], coord2[sharp], 2))
			return (0);
		sharp++;
	}
	return (1);
}

static int	ft_connect(char ***coord)
{
	size_t	forward;
	int		backward;

	forward = 0;
	while (coord[forward] != NULL)
	{
		backward = (int)(forward - 1);
		while (backward >= 0)
		{
			if (ft_piececmp(coord[forward], coord[(size_t)backward]) == 1)
			{
				coord[forward][5][0] = (char)backward;
				break ;
			}
			backward--;
		}
		forward++;
	}
	return (0);
}

/*
**	ft_preprocess is a function managing the preprocessing part of the
**	programme. Size_t i stands for the number of pieces as counted earlier in
**	the validation part.
**	First it refers to ft_create_coord - allocating memory for couples of
**	coordinates tables. Then it refers to ft_get_pos - getting coordinates
**	positions and stocking it in coord -. The function then refers to
**	put_upper_left.c.
**	The function returns coord.
*/

char		***ft_preprocess(size_t i, char ***piece)
{
	size_t	j;
	size_t	k;
	char	***coord;

	j = 0;
	k = 0;
	coord = NULL;
	if (ft_create_coord(i, &coord) == 1)
		return (NULL);
	ft_get_pos(j, k, piece, coord);
	ft_connect(coord);
	ft_up_left(coord);
	return (coord);
}
