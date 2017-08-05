/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_upper_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:21:40 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/05 18:56:48 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The 2 following static functions are quite explicit. They check whether if
**	a piece can be placed in the upper left corner or not ; and do it
**	accordingly.
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

/*
**	ft_up_left is a function managing the end of the preprocessing part of the
**	programme, e.g. putting a piece in the upper left corner if needed.
**	It returns 0 if everything went well.
*/

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
