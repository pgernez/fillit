/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:07:13 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/19 15:35:07 by pgernez          ###   ########.fr       */
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
	while (tetritab[k] != NULL)
	{
		j = 0;
		while (tetritab[k][j] != 0)
		{
			i = 0;
			while (tetritab[k][j][i] != 0)
				i++;
			if (tetritab[k][j][4] != '\n')
			{
				printf("problem ln\n");
				return (1);
			}
			j++;
		}
		k++;
	}
	return (0);
}

/*
**  ft_sharp_check returns 0 if we count 4 # in a piece or 1 if != 4
*/

static int	ft_sharp_check(char ***tetritab)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	sharp;

	k = 0;
	while (tetritab[k] != NULL)
	{
		sharp = 0;
		j = 0;
		while (tetritab[k][j] != 0)
		{
			i = 0;
			while (tetritab[k][j][i] != 0)
			{
				if (tetritab[k][j][i++] == '#')
					sharp++;
			}
			j++;
		}
		if (sharp != 4)
			return (1);
		k++;
	}
	return (0);
}

/*
**  ft_dots_check returns 0 if the rest of the piece is filled with dots or 1
**  if not.
*/

static int	ft_dots_check(char ***tetritab)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	dots;

	k = 0;
	while (tetritab[k] != NULL)
	{
		dots = 0;
		j = 0;
		while (tetritab[k][j] != 0)
		{
			i = 0;
			while (tetritab[k][j][i] != 0)
			{
				if (tetritab[k][j][i++] == '.')
					dots++;
			}
			j++;
		}
		if (dots != 12)
			return (1);
		k++;
	}
	return (0);
}

/*
**  ft_pattern_check returns 0 if the pattern is correct or 1 if not.
*/

static int	ft_pattern_check(char ***tetritab)
{
	if (tetritab == NULL)
		return (1);
	return (0);
}

int			ft_input_check(char ***tetritab)
{
	ft_backslash_check(tetritab);
	ft_sharp_check(tetritab);
	ft_dots_check(tetritab);
	ft_pattern_check(tetritab);
	return (0);
}
