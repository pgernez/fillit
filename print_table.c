/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 11:45:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/16 15:52:37 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Cette fonction prend une chaine de caracteres str en argument et
**	sur la sortie standard.
**	Usage : ft_putstr(chaine de caractères)
*/

void	ft_putstr(char *str)
{
	size_t	k;

	// Initialisation du compteur
	k = 0;
	// Tant que mon (k + 1)ieme caractère de str est non null
	while (str[k] != 0)
	{
	//	str[k] : (k + 1)ième caractère de type char
	//	J'affiche le caractère str[k] qui est à l'adresse
		write(1, &str[k], 1);
		k++;
	}
}

void	ft_print_piece(char **piece)
{
	size_t	j;

	j = 0;
	while (piece[j] != 0)
	{
		ft_putstr(piece[j]);
		j++;
	}
}

void	ft_print_tetritab(char ***tetritab)
{
	size_t	i;
	char	d;
	char	u;

	i = 0;
	while (tetritab[i] != 0)
	{
	//	j = '0' + i;
		d = i / 10 + '0';
		u = i % 10 + '0';
		ft_putstr("-------- ");
		write(1, &d, 1);
		write(1, &u, 1);
		ft_putstr(" --------\n");
		write(1, "|", 1);
		ft_print_piece(tetritab[i]);
		write(1, "|", 1);
		i++;
	}
}
