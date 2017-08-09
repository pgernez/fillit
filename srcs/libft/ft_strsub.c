/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:23:36 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 19:24:53 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] != 0 && i < len)
		fresh[i++] = s[start++];
	fresh[i] = 0;
	return (fresh);
}
