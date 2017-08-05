/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:24:48 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/05 18:57:05 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_create_coord allocates memory for the tables of coordinates. The 5th
**	line aims at stocking the letter thanks to ft_memset, allowing us to use it
**	later for the solving part. It returns 1 if the allocation fails and 0
**	otherwise.
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
		if (!((*coord)[k] = (char**)malloc(sizeof(char*) * 5)))
			return (1);
		while (j < 5)
		{
			if (!((*coord)[k][j] = (char*)malloc(sizeof(char) * 2)))
				return (1);
			j++;
		}
		ft_memset((*coord)[k][4], k + 'A', 1);
		k++;
	}
	return (0);
}

/*
**	ft_get_pos stocks couples of coordinates in coord. It - sadly - takes 2
**	size_t as parameters to stick to the Norm.
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

/*
**	ft_preprocess is a function managing the preprocessing part of the
**	programme. Size_t i stands for the number of pieces as counted earlier in
**	the validation part.
**	First it refers to ft_create_coord - allocating memory for couples of
**	coordinates tables. Then it refers to ft_get_pos - getting coordinates
**	positions and stocking it in coord -. The function then refers to
**	put_upper_left.c. See you there ;).
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
	ft_up_left(coord);
	return (coord);
}
