/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:53:30 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/16 18:53:35 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	   ft_putstr(char *str)
{
	size_t	k;

	k = 0;
	// Tant que mon (k + 1)ieme caractère de str est non null
	while (str[k] != 0)
	{
	//	str[k] : (k + 1)ième caractère de type char
	//	J'affiche le caractère str[k] qui est à l'adresse
		write(1, &str[k], 1);
		k++;
	}
}
