/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:56:10 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/30 23:30:17 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_init_carpet initializes the carpet structure and allocates memory for
**	the final map to solve. It returns 1 if the allocations fails and 0 in case
**	of success.
*/

static int	ft_init_carpet(t_carpet *carpet, size_t n)
{
	size_t	line;

	carpet->map = NULL;
	carpet->x = 0;
	carpet->y = 0;
	if (!(carpet->map = (char**)malloc(sizeof(char*) * (n + 1))))
		return (1);
	line = 0;
	while (line < n)
	{
		if (!((carpet->map)[line] = (char*)malloc(sizeof(char) * (n + 1))))
			return (1);
		line++;
	}
	return (0);
}

/*
**	ft_set_piece drops a piece on an available space such as there is no # out
**	of the map and # must be placed on '.'. ft_set_piece also converts # in
**	letters according to their position in the pieces list. It returns 1 if
**	the piece was successfully dropped and 0 if not.
*/

static int	ft_set_piece(t_carpet *carpet, char **coord_piece)
{

// k + 'A'
	return ();
}

static int	ft_withdraw(t_carpet *carpet, char **coord)
{
	return ();
}

static int	ft_solve(t_carpet *carpet, char ***coord, size_t current, size_t nb_piece)
{
	if (current == nb_piece)
		return (1);  // J'ai réussi à tout placer
	if (ft_set_piece(carpet, coord[k]) == 1)
	{
		if (ft_solve(carpet, coord[k], current + 1, nb_piece) == 1)
			return (1);
		ft_withdraw(carpet, coord);
	}

	return (0);
}
