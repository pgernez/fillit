/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:30:31 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/16 17:00:32 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>

/*
**	introduire dans read_file un compteur des pieces.
**	malloc avec le nombre de pieces
**	quand read : tous les 4\n, compter une piece.
**	printf("-------- Lu et stocké à k : %zu -- i : %zu\n|%s|\n -- len : %zu\n",
**	k, i, (*new)[k][i], strlen((*new)[k][i]));
**	printf("Dernière valeur de read retournée : %d\n", ret);
**	printf("******** Valeur de read_file : %d\n", status);
*/

static int		ft_create_tetritab(char ****new)
{
	size_t	j;
	size_t	k;

	k = 0;
	if (!((*new) = (char***)malloc(sizeof(char**) * 27)))
		return (0);
	while (k < 27)
	{
		j = 0;
		if (!((*new)[k] = (char**)malloc(sizeof(char*) * 5)))
			return (0);
		while (j < 5)
		{
			if (!((*new)[k][j] = (char*)malloc(sizeof(char) * 6)))
				return (0);
			j++;
		}
		k++;
	}
	return (0);
}

static size_t	ft_read_file(int fd, size_t k, char ****new)
{
	int		ret;
	size_t	i;
	size_t	step;

	i = 0;
	step = 5;
	while ((ret = read(fd, (*new)[k][i], step)) > 0)
	{
		(*new)[k][i][ret] = 0;
		if (i == 0 && step == 1)
			i = 0;
		else
			i++;
		step = 5;
		if (i == 4)
		{
			step = 1;
			(*new)[k][i] = NULL;
			k++;
			i = 0;
		}
	}
	(*new)[k] = NULL;
	return (0);
}

// static size_t	ft_len_file(char *new)
// {
// 	size_t	len;
//
// 	len = ft_strlen(new);
// 	return (len);
// }

int				ft_open_read_close(char **argv, char ****new)
{
	int		fd;
	size_t	k;
	size_t	i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	ft_create_tetritab(new);
	k = 0;
	i = 0;
	// ft_len_file(*argv);
	// printf("len : %zu\n", ft_strlen(*argv));
	// printf("len : %zu\n", strlen(*argv));
	ft_read_file(fd, k, new);
	// 	ft_putstr("File is empty.\n");
	if (close(fd) == -1)
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	char	***piece;
	int		status;

	if (argc == 1)
	{
		ft_putstr("usage: ./fillit tetriminos_file\nFile name missing\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\nToo many arguments\n");
		return (0);
	}
	piece = NULL;
	status = ft_open_read_close(argv, &piece);
	ft_input_check(piece);
	ft_print_tetritab(piece);
	return (0);
}
