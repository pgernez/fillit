/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:34:02 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 18:06:17 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if ((int)(size - len_dst - 1) >= 0)
	{
		ft_strncat(dst, src, size - len_dst - 1);
		return (len_dst + len_src);
	}
	else
		return (size + len_src);
}
