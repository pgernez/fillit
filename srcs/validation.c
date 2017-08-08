/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:07:13 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/08 15:00:11 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	ft_backslash_check returns 0 if there are 4 well-positionned \n or 1 if
**	!= 4 or not at the end of a line.
*/

static int	ft_backslash_check(char ***tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	while (tab[k] != NULL)
	{
		j = 0;
		while (tab[k][j] != 0)
		{
			i = 0;
			while (tab[k][j][i] != 0)
				i++;
			if (tab[k][j][4] != '\n')
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

/*
**	ft_sharp_check returns 0 if we count 4 # in a piece or 1 if != 4.
*/

static int	ft_sharp_check(char ***tab)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	sharp;

	k = 0;
	while (tab[k] != NULL)
	{
		sharp = 0;
		j = 0;
		while (tab[k][j] != 0)
		{
			i = 0;
			while (tab[k][j][i] != 0)
			{
				if (tab[k][j][i++] == '#')
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
**	ft_dots_check returns 0 if the rest of the piece is filled with dots or 1
**	otherwise.
*/

static int	ft_dots_check(char ***tab)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	dots;

	k = 0;
	while (tab[k] != NULL)
	{
		dots = 0;
		j = 0;
		while (tab[k][j] != 0)
		{
			i = 0;
			while (tab[k][j][i] != 0)
			{
				if (tab[k][j][i++] == '.')
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
**	ft_pattern_check returns 0 if the pattern is correct or 1 otherwise.
*/

static int	ft_pattern_check(char **tab)
{
	size_t	pattern;
	size_t	j;
	size_t	i;

	pattern = 0;
	j = 0;
	while ((i = 0) || tab[j] != 0)
	{
		while (tab[j][i] != 0)
		{
			if (tab[j][i] == '#' && tab[j][i + 1] == '#')
				pattern++;
			if (tab[j][i] == '#' && tab[j][i - 1] == '#')
				pattern++;
			if (j != 0 && tab[j][i] == '#' && tab[j - 1][i] == '#')
				pattern++;
			if (j < 3 && tab[j][i] == '#' && tab[j + 1][i] == '#')
				pattern++;
			i++;
		}
		j++;
	}
	if (pattern != 6 && pattern != 8)
		return (1);
	return (0);
}

/*
**	ft_input_check is a function managing the validation part of the
**	programme. The char*** stands for the table that stocks the pieces of the
**	description file.
**	The function returns the number of pieces of the description file if
**	everything went well or an 'error' message otherwise.
*/

size_t		ft_input_check(char ***tab)
{
	size_t	k;

	k = 0;
	while (tab[k] != NULL)
	{
		if (ft_backslash_check(tab) == 1 || ft_sharp_check(tab) == 1
			|| ft_dots_check(tab) == 1 || ft_pattern_check(tab[k]) == 1)
		{
			ft_putstr("error\n");
			return (42);
		}
		k++;
	}
	if (k == 0)
	{
		ft_putstr("error\n");
		return (42);
	}
	return (k);
}
