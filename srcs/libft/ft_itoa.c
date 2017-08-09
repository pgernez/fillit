/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:05:57 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 19:52:31 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*fresh;
	size_t			len;
	size_t			sign;
	unsigned int	cpy;

	len = 2;
	sign = (n < 0) ? 1 : 0;
	cpy = (sign == 1) ? -n : n;
	while ((cpy = cpy / 10) > 0)
		len++;
	if (!(fresh = (char *)malloc(sizeof(char) * (len + sign))))
		return (NULL);
	fresh[len + sign - 1] = '\0';
	len--;
	cpy = (sign == 1) ? -n : n;
	while (cpy >= 9)
	{
		fresh[len + sign - 1] = cpy % 10 + '0';
		cpy = cpy / 10;
		len--;
	}
	fresh[len + sign - 1] = cpy + '0';
	fresh[0] = (sign == 1) ? '-' : fresh[0];
	return (fresh);
}
