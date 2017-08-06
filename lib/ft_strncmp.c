/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:30:21 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/06 16:40:45 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	i = 0;
	tmps1 = (unsigned char*)s1;
	tmps2 = (unsigned char*)s2;
	if (tmps1 == NULL && n == 0)
		return (0);
	while (i < (n - 1) && tmps1[i] != 0 && tmps2[i] != 0)
	{
		if (tmps1[i] != tmps2[i])
			break ;
		else
			i++;
	}
	if (n != 0)
		return ((int)(tmps1[i] - tmps2[i]));
	return (0);
}
