/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:59:00 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/15 19:18:03 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1))))
		return (NULL);
	while (s1[i] != 0)
		fresh[k++] = s1[i++];
	while (s2[j] != 0)
		fresh[k++] = s2[j++];
	fresh[k] = 0;
	return (fresh);
}
