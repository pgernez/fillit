/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgernez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:30:31 by pgernez           #+#    #+#             */
/*   Updated: 2017/07/09 23:10:11 by pgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	read_file(char **argv, char ***new)
{
	int		fd;
	int		ret;
	size_t	i;
	size_t	nb_line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	nb_line = 5;
	if (!(*new = (char**)malloc(sizeof(char*) * (nb_line + 1))))
		return (0);
	i = 0;
	while (i < 5)
	{
		if (!((*new)[i] = (char*)malloc(sizeof(char) * (5 + 1))))
			return (0);
		i++;
	}
	i = 0;
	while ((ret = read(fd, (*new)[i], BUF_SIZE)) > 0)
	{
		(*new)[ret] = 0;
		i++;
	}
	printf("Dernière valeur de read retournée : %d\n", ret);
	(*new)[i] = 0;
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**piece;
	int		status;

	(void)argc;
	piece = NULL;
	status = read_file(argv, &piece);
	print_table(piece);
	return (0);
}
