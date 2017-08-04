/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_upper_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:21:40 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/03 15:55:37 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	printf("--------- Pièce %zu --------\n", k);
**	printf("line : %c col : %c\n", coord[k][i][0] + '0', coord[k][i][1] + '0');
*/

static int	ft_can_sub(char **coord, size_t col)
{
	size_t	line;

	line = 0;
	while (line < 4)
	{
		if (coord[line][col] == 0)
			return (0);
		line++;
	}
	return (1);
}

static int	ft_sub(char **coord, size_t col)
{
	size_t	line;

	line = 0;
	while (line < 4)
	{
		coord[line][col] -= 1;
		line++;
	}
	return (0);
}

int			ft_up_left(char ***coord)
{
	size_t	k;

	k = 0;
	while (coord[k] != NULL)
	{
		while (ft_can_sub(coord[k], 0) == 1)
			ft_sub(coord[k], 0);
		while (ft_can_sub(coord[k], 1) == 1)
			ft_sub(coord[k], 1);
		k++;
	}
	return (0);
}

void		ft_print_coord(char ***coord)
{
	size_t	k;
	size_t	i;

	k = 0;
	while (coord[k] != NULL)
	{
		i = 0;
		while (i < 4)
			i++;
		k++;
	}
}
