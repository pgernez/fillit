/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:16:50 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 18:16:39 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_tmp;
	char	*s_tmp;

	i = 0;
	c_tmp = (char)c;
	s_tmp = (char*)s;
	while (s[i])
	{
		if (s_tmp[i] == c_tmp)
			return ((char*)&s[i]);
		else
			i++;
	}
	if (c_tmp == '\0')
		return ((char*)&s[i]);
	else
		return (0);
}
