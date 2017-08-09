/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:07:57 by pgernez           #+#    #+#             */
/*   Updated: 2017/02/07 22:26:16 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = NULL;
	if (*alst != NULL)
	{
		while (*alst)
		{
			tmp = (*alst)->next;
			ft_lstdelone(alst, (*del));
			(*alst) = tmp;
		}
	}
}
