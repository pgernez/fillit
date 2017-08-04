/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 11:45:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/04 16:41:08 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Cette fonction prend une chaine de caracteres str en argument et
**	sur la sortie standard.
*/

static void	ft_print_piece(char **piece)
{
	size_t	j;

	j = 0;
	while (piece[j] != 0)
	{
		ft_putstr(piece[j]);
		j++;
	}
}

void		ft_print_tetritab(char ***tetritab)
{
	size_t	i;
	char	d;
	char	u;

	i = 0;
	while (tetritab[i] != 0)
	{
		d = i / 10 + '0';
		u = i % 10 + '0';
		ft_putstr("-------- ");
		write(1, &d, 1);
		write(1, &u, 1);
		ft_putstr(" --------\n");
		write(1, "|", 1);
		ft_print_piece(tetritab[i]);
		write(1, "|", 1);
		write(1, "\n", 1);
		i++;
	}
}
