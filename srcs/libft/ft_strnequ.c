/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:02:35 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 19:21:07 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (i == n)
		return (1);
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}
