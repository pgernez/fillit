/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:21:29 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 23:37:08 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	{
		if (fresh == 0)
			return (NULL);
	}
	while (s[i])
	{
		fresh[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	fresh[i] = 0;
	return (fresh);
}
