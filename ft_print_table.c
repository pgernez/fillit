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

void	print_table(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		ft_putstr(tab[i++]);
}

/*
int				main(void)
{
	char	*tab[10];
	char	**new;
	size_t	i;
	size_t	nb_line;

	i = 0;
	nb_line = 5;
	tab[0] = "Hello";
	tab[1] = " mes";
	tab[2] = " petites";
	tab[3] = " écrevisses";
	tab[4] = " rouges.";
	if (!(new = (char**)malloc(sizeof(char*) * (nb_line + 1))))
		return (0);
	while (tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = 0;
	print_table(tab);
	ft_putchar('\n');
	print_table(new);
	return (0);
}
*/
