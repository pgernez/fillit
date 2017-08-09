/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:06:41 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/04 23:26:34 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	countstr(char const *s, char c)
{
	size_t	i;
	size_t	nb_str;

	i = 0;
	nb_str = 0;
	if (s[0] != c)
		nb_str++;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i - 1] == c)
			nb_str++;
		i++;
	}
	return (nb_str);
}

static size_t	len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (countstr(s, c) + 1))))
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != 0)
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) * (len(&s[i], c) + 1))))
				return (0);
			while (s[i] != c && s[i] != 0)
				tab[j][k++] = s[i++];
			tab[j++][k] = 0;
		}
	}
	tab[j] = 0;
	return (tab);
}
