/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:30:31 by pgernez           #+#    #+#             */
/*   Updated: 2017/03/12 19:34:51 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	read_file(char **argv, char **new)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	size_t	i;
	size_t	nb_line;

	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, new[i], BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	/* doit lire **argv (one piece) la stocker dans new et afficher new
	*/
	char **new;
	int	status;
	while (argc)
	 	;
	status = read_file(argv, new);
	print_table(new);
	return (0);
}


/*
i = 0;
nb_line = 5;
if (fd == -1)
	return (1);
if (!(new = (char**)malloc(sizeof(char*) * (nb_line + 1))))
	return (0);
while (argv[1])
{
	new[i] = argv[i];
	i++;
}
new[i] = 0;
*/
