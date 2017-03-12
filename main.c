/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:46 by pgernez           #+#    #+#             */
/*   Updated: 2017/03/12 19:35:13 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	manage_arg(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
		read_file(argv);
	return (0);
}

int	main(int argc, char **argv)
{
	manage_arg(argc, argv);
	return (0);
}
