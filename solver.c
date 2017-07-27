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

/*
**	1. Malloc mon tapis : ft_create_map
**	2. Malloc un tableau pouvant stocker des tableaux de 4 tableaux de 2 ints
**	(4 tableaux de 2 ints = 1 pièce)
**	3. Stocker par 4 tableaux de 2 ints
**	4. Coordonnées
*/

// ft_get_pos_of_sharp(char **piece, int ***relative_pos)
// ft_get_pos_of_sharp(char ***piece, int ****relative_pos)

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

// faire une fonction qui le créée, qui prend en argument ton vrai nombre de pièces, et l'adresse où tu vas le créer, et qui retourne 0 si la création a été correcte, et 1 sinon.

static int	**ft_create_tab_pos(int k, char ****tab_pos)
{
	if (!((*tab_pos) = (char***)malloc(sizeof(char**) * k + 1)))
		return (1);
	return (0);
}

static int	**ft_get_sharp_pos(char ****tab_pos)
{
	ft_create_tab_pos(k, tab_pos);
	//remplis le tableau précédemment créé
	// faire une fonction qui te fait passer de ton tableau de pièces représentées par un tableau de lignes, à un tableau de pièces représentées par un tableau (de taille 4) de 2 entiers (correspondant aux coordonnées de ta pièce)
	return (0);
}


int	*ft_solve(size_t n, char ****tab_pos)
{
	if (ft_create_map(n) == 1)
		return (1);
	ft_get_sharp_pos();
	return (0);
}

// Alors, tu dois faire une fonction qui te fait passer de ton tableau de pièces représentées par un tableau de lignes, à un tableau de pièces représentées par un tableau (de taille 4) de 2 entiers (correspondant aux coordonnées de ta pièce)
//
// Pour ca, tu dois déjà faire une fonction qui le créée, qui prend en argument ton vrai nombre de pièces, et l'adresse où tu vas le créer, et qui retourne 0 si la création a été correcte, et 1 sinon.
//
// où tab_positions est l'adresse du tableau que tu vas créer (et donc tu modifies *tab_positions comme dans le read_file)
//
// int  ft_create_tab_pos(char ****tab_positions)
// {
// }
//
// Une fois créé, tu remplis ce tableau à partir du tab(validation). De sorte à récupérer chaque coordonnée de chaque dièse.
//
// int  ft_create_tab_pos(char ***tab_positions)
// {
// }
//
// Tu retournes 0 si tout c'est bien passé par exemple (que tu as bien eu 4 dièses par pièces, je sais pas encore)
