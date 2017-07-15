/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:30:31 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/09 23:10:11 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	introduire dans read_file un compteur des pieces.
**	malloc avec le nombre de pieces
**	quand read : tous les 4\n, compter une piece
*/

// static void	ft_create_tetritab()
// {
	// size_t	i;
	// size_t	k;
	// size_t	nb_piece;
	//
// 	k = 0;
// 	nb_piece = 4;
// 	if (!(*new = (char***)malloc(sizeof(char**) * nb_piece)))
// 		return (0);
// 	while (k < 5)
// 	{
// 		i = 0;
// 		if (!((*new)[k] = (char**)malloc(sizeof(char*) * 5)))
// 			return (0);
// 		while (i < 5)
// 		{
// 			if (!((*new)[k][i] = (char*)malloc(sizeof(char) * 6)))
// 				return (0);
// 			i++;
// 		}
// 		k++;
// 	}
// }

int	ft_read_file(char **argv, char ****new)
{
	int		fd;
	int		ret;
	size_t	i;
	size_t	k;
	size_t	nb_piece;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	k = 0;
	nb_piece = 4;
	if (!(*new = (char***)malloc(sizeof(char**) * nb_piece)))
		return (0);
	while (k < 5)
	{
		i = 0;
		if (!((*new)[k] = (char**)malloc(sizeof(char*) * 5)))
			return (0);
		while (i < 5)
		{
			if (!((*new)[k][i] = (char*)malloc(sizeof(char) * 6)))
				return (0);
			i++;
		}
		k++;
	}
	i = 0;
	k = 0;
	while ((ret = read(fd, (*new)[k][i], 5)) > 0)
	{
		printf("-------- Lu et stocké à k : %zu -- i : %zu\n|%s|\n", k, i, (*new)[k][i]);
		// while (k < 5)
		// {
		// 	i = 0;
		// 	while (i < 4)
		// 	{
		// 		printf("-------- k = %zu --- i = %zu\n", k, i);
		// 		printf("-------- Valeur de la i+... : \n%s\n", (*new)[k][i]);
		// 		i++;
		// 	}
		// 	k++;
		// }
		// (*new)[k][ret] = 0;
	}
	printf("Dernière valeur de read retournée : %d\n", ret);
	(*new)[k][i] = 0;
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	***piece;
	int		status;

	(void)argc;
	piece = NULL;
	status = ft_read_file(argv, &piece);
	// printf("******** Valeur de read_file : %d\n", status);
	printf("hello\n");
	ft_print_tetritab(piece);
	printf("salut\n");
	return (0);
}
