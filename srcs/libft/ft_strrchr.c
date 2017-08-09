/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:10:03 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 18:18:26 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char	*s_tmp;
	char	c_tmp;
	size_t	i;

	c_tmp = (char)c;
	s_tmp = (char*)s;
	i = ft_strlen(s);
	if (c_tmp == '\0')
		return ((char*)&s[i]);
	while (i != 0)
	{
		if (s_tmp[i - 1] == c_tmp)
			return ((char*)&s[i - 1]);
		else
			i--;
	}
	return (0);
}
