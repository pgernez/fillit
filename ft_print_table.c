/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:33:19 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/09 16:55:33 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fonction qui prend un tableau de chaînes de caractères en entrée et qui
** affiche le contenu de ce tableau. Chaque ligne sera mise à la suite l'une de
** l'autre
*/

void	print_table(int argc, char **tab)
{
	size_t	i;

	i = 0;
	if (argc != 2)
		ft_putstr("usage: ./fillit pieces_file\n");
	else
	{
		while (tab[i])
			ft_putstr(tab[i++]);
	}
}
