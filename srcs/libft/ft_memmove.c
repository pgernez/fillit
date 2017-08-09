/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:00:51 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 17:37:16 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (src < dst)
	{
		i = len;
		while (i != 0)
		{
			((char*)dst)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
