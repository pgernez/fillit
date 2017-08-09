/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:02:48 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 18:23:24 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
	while (big_str[j])
	{
		i = 0;
		while (little_str[i] && big_str[j + i])
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
