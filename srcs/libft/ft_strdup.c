/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:56:55 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 20:34:42 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != 0)
		j++;
	if (!(dup = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i = i + 1;
	}
	dup[j] = 0;
	return (dup);
}
