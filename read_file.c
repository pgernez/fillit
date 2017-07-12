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

/*while (i != '\n')
{
	if ((**new)[i] != '\n')
		i++;
	else
		nb_n++;
}*/
	//printf("2. Nombre de backslah n : %zu\n", nb_n);

int	read_file(char **argv, char ***new)
{
	int		fd;
	int		ret;
	size_t	i;
	size_t	nb_line;
	size_t	nb_piece;
	//size_t	nb_n;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	nb_line = 5;
	nb_piece = 10;
	//nb_n = 0;
	if (!(new = (char***)malloc(sizeof(char**) * (nb_piece + 1))))
		return (0);
	if (!(*new = (char**)malloc(sizeof(char*) * (nb_line + 1))))
		return (0);
	while (i < 5)
	{
		if (!((*new)[i] = (char*)malloc(sizeof(char) * (5 + 1))))
			return (0);
		i++;
	}
	i = 0;
	while ((ret = read(fd, (*new)[i], BUF_SIZE)) > 0)
	{
		(*new)[ret] = 0;
		i++;
	}
	printf("Dernière valeur de read retournée : %d\n", ret);
	(*new)[i] = 0;
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**piece;
	int		status;

	(void)argc;
	piece = NULL;
	status = read_file(argv, &piece);
	printf("hello\n");
	print_table(argc, piece);
	printf("salut\n");
	return (0);
}
