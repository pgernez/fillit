/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:30:31 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/05 23:32:28 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_create_piecetab allocates memory for the pieces as described in the
**	entry file.
**	First for the whole tab, then for the pieces (every 5 lines including the
**	last \n) and for every char (including the final \0).
**	ft_memset is refered to init the tab.
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
			ft_memset((*new)[k][j], 0, 6);
			j++;
		}
		k++;
	}
	return (0);
}

/*
**	ft_read_file read the file and alternates the step between 1 and 5 to
**	evacuate extra \n.
**	Size_t length_piece is used to avoid segmentation faults from misplaced
**	\0 in the description file.
**	It - sadly - takes 2 size_t as parameters to stick to the Norm.
**	It returns 0 in case of success and 0 if not.
*/

static int	ft_read_file(int fd, size_t j, size_t k, char ****new)
{
	int		ret;
	size_t	step;
	size_t	length_piece;

	step = 5;
	length_piece = 0;
	while ((ret = read(fd, (*new)[k][j], step)) > 0 && k < 26)
	{
		length_piece += ret;
		if (j == 0 && step == 1)
			j = 0;
		else
			j++;
		step = 5;
		if (j == 4 && (step = 1))
		{
			length_piece = 0;
			(*new)[k++][j] = NULL;
			j = 0;
		}
	}
	if (ret != 0 || length_piece != 0)
		return (1);
	(*new)[k] = NULL;
	return (0);
}

/*
**	ft_open_read_close is a function managing the reading part of the
**	programme.
**	It refers to the previous static functions and put an 'error' message if
**	any action failed. Char ****new allows us to stock the bytes of the
**	description file.
**	It returns 0 in case of success and 1 if not.
*/

int			ft_open_read_close(char **argv, char ****new)
{
	int		fd;
	size_t	k;
	size_t	j;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (ft_create_piecetab(new) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	j = 0;
	k = 0;
	if (ft_read_file(fd, j, k, new) == 1 || close(fd) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
