/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 23:02:20 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/19 21:30:56 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trim;

	i = 0;
	start = 0;
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (end != 0 && (s[end - 1] == ' ' || s[end - 1] == '\n'
				|| s[end - 1] == '\t'))
		end--;
	if (end == 0)
		return ("");
	if (!(trim = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start < end)
		trim[i++] = s[start++];
	trim[i] = 0;
	return (trim);
}
