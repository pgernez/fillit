/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:07:13 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/17 17:57:22 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_backslash_check returns 0 if there are 4 well-positionned \n or 1 if != 4
**	or not at the end of a line.
*/

static int	ft_backslash_check(char ***tetritab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	while (k < 27)
	{
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (tetritab[k][j][i] == '\n')
					return (1);
				else
					return (0);
				// printf("-------- k : %zu --- j : %zu --- i : %zu\n", k, j, i);
				i++;
			}
			if (tetritab[k][j][4] != '\n')
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

/*
**  ft_sharp_check returns 0 if we count 4 # in a piece or 1 if != 4
*/

// static int	ft_sharp_check(char ***tetritab)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;
// 	size_t	sharp;
//
// 	printf("hello\n");
// 	k = 0;
// 	while (k < 27)
// 	{
// 		sharp = 0;
// 		j = 0;
// 		while (j < 4)
// 		{
// 			i = 0;
// 			printf("hello\n");
// 			while (i < 4)
// 			{
// 				printf("--- sharp : %zu --- k : %zu --- j : %zu --- i : %zu\n", sharp, k, j, i);
// 				if (tetritab[k][j][i] == '#')
// 					sharp++;
// 				i++;
// 			}
// 			if (sharp != 4)
// 				return (1);
// 			j++;
// 		}
// 		k++;
// 	}
// 	return (0);
// }

/*
**  ft_dots_check returns 0 if the rest of the piece is filled with dots or 1
**  if not.
*/

// static int  ft_dots_check()
// {
//     return (0);
// }

/*
**  ft_pattern_check returns 0 if the pattern is correct or 1 if not.
*/

// static int  ft_pattern_check()
// {
//     return (0);
// }
//
// int     ft_input_check(char ****tetritab)
// {
//     ft_backslash_check(tetritab);
//     ft_sharp_check();
//     ft_dots_check();
//     ft_pattern_check();
//     return (0);
// }

int				main(int argc, char **argv)
{
	char	***piece;
	int		status;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
		return (0);
	}
	piece = NULL;
	status = ft_open_read_close(argv, &piece);
	ft_backslash_check(piece);
	// ft_sharp_check(piece);
	ft_print_tetritab(piece);
	return (0);
}
