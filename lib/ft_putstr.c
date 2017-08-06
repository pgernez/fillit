/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <pgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 18:53:30 by pgernez           #+#    #+#             */
/*   Updated: 2017/08/06 16:40:41 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	ft_putstr(char *str)
{
	size_t	k;

	k = 0;
	while (str[k] != 0)
	{
		write(1, &str[k], 1);
		k++;
	}
}
