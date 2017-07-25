/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:30:31 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/25 10:25:37 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	introduire dans read_file un compteur des pieces.
**	malloc avec le nombre de pieces
**	quand read : tous les 4\n, compter une piece.
**	printf("-------- Lu et stocké à k : %zu -- i : %zu\n|%s|\n -- len : %zu\n",
**	k, i, (*new)[k][i], strlen((*new)[k][i]));
*/

static int	ft_create_piecetab(char ****new)
{
	size_t	j;
	size_t	k;

	k = 0;
	if (!((*new) = (char***)malloc(sizeof(char**) * 27)))
		return (1);
	while (k < 27)
	{
		j = 0;
		if (!((*new)[k] = (char**)malloc(sizeof(char*) * 5)))
			return (1);
		while (j < 5)
		{
			if (!((*new)[k][j] = (char*)malloc(sizeof(char) * 6)))
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

static int	ft_read_file(int fd, size_t k, char ****new)
{
	int		ret;
	size_t	i;
	size_t	step;

	i = 0;
	step = 5;
	while ((ret = read(fd, (*new)[k][i], step)) > 0 && k < 26)
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
			(*new)[k++][i] = NULL;
			i = 0;
		}
	}
	if (ret != 0)
		return (1);
	(*new)[k] = NULL;
	return (0);
}

int			ft_open_read_close(char **argv, char ****new)
{
	int		fd;
	size_t	k;
	size_t	i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (ft_create_piecetab(new) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	k = 0;
	i = 0;
	if (ft_read_file(fd, k, new) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
