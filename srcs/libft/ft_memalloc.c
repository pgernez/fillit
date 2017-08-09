/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:05:47 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 20:23:37 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	zone = (void*)malloc(sizeof(size_t) * size);
	{
		if (zone == 0)
			return (NULL);
	}
	ft_bzero(zone, size);
	return (zone);
}
