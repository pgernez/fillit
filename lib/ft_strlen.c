/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:41:11 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/04 16:31:09 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str[len] == 0)
		return ('0');
	while (str[len] != 0)
		len++;
	return (len);
}
