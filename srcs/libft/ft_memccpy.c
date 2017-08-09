/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 23:23:14 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/21 21:44:59 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	i = 0;
	tmp_d = (unsigned char*)dst;
	tmp_s = (unsigned char*)src;
	if (n == 0)
		return (NULL);
	while (tmp_s[i] != (unsigned char)c && i < n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	if (tmp_s[i] == (unsigned char)c && i != n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
		return (&((char*)dst)[i]);
	}
	return (NULL);
}
