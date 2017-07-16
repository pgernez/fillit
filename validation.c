/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:07:13 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/16 18:07:16 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  ft_backslash_check returns 0 if there are 4 well-positionned \n or 1 if != 4
**  or not at the end of a line.
*/

static int  ft_backslash_check(char ****tetritab)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    printf("Coucou\n");
    while (i < 4)
    {
        if ((**tetritab)[j][i] == '\n')
        {
            printf("Oops.\n");
            return (1);
        }
        else
            i++;
    }
    i = 0;
    while (j < 27)
    {
        if ((**tetritab)[j][4] == '\n')
        {
            printf("Cool !\n");
            j++;
        }
        else
        {
            printf("NUL.\n");
            return (1);
        }
    }
    // {
    //     if (i == '\n')
    //         return (1);
    //     i++;
    // }
    // if (
        // return (1);
    return (0);
}

/*
**  ft_sharp_check returns 0 if we count 4 # in a piece or 1 if != 4 or at the
**  end of a line.
*/

// static int  ft_sharp_check()
// {
//     return (0);
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
    ft_backslash_check(&piece);
	ft_print_tetritab(piece);
	return (0);
}
