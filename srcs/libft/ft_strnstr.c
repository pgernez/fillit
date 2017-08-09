/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:15:49 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 18:24:25 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_str;
	char	*little_str;

	i = 0;
	j = 0;
	big_str = (char*)big;
	little_str = (char*)little;
	if (little_str[i] == 0)
		return ((char*)big);
	while (big_str[j] && j < len)
	{
		i = 0;
		while (little_str[i] && big_str[j + i] && (j + i) < len)
		{
			if (little_str[i] != big_str[j + i])
				break ;
			i++;
		}
		if (!little_str[i])
			return ((char*)big + j);
		j++;
	}
	return (0);
}
