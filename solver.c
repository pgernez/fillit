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

static char	**ft_create_map(size_t n)
{
	char	**map;
	size_t	line;

	if (!(map = (char**)malloc(sizeof(char*) * (n + 1))))
		return (1);
	line = 0;
	while (line < n)
	{
		if (!(map[line] = (char*)malloc(sizeof(char) * (n + 1))))
			return (1);
		line++;
	}
	return (map);
}

int			ft_get_pos_of_sharp()
{
	return ();
}

// ft_get_pos_of_sharp(char **piece, int ***relative_pos)
// ft_get_pos_of_sharp(char ***piece, int ****relative_pos)
