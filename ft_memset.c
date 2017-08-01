/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:52:55 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 20:26:09 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	k;

	k = 0;
	tmp = (char*)b;
	if (b == NULL && len == 0)
		return (NULL);
	while (k < len)
	{
		tmp[k] = (unsigned char)c;
		k++;
	}
	return (b);
}
