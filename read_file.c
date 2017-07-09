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
	size_t	i;
	size_t	nb_line;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	nb_line = 5;
	if (!(new = (char**)malloc(sizeof(char*) * (nb_line + 1))))
		return (0);
	if (!(new[0] = (char*)malloc(sizeof(char) * (4 + 1))))
		return (0);
	if (fd == -1)
		return (1);
	write(1, "Je suis la 3\n", 13);
	while ((ret = read(fd, new[i], BUF_SIZE)) > 0)
	{
		printf("ret vaut: %d et new[i] : |%s|\n", ret, new[i]);
		//new[] = 0;
		i++;
	}
	write(1, "Je suis la 6\n", 13);
	new[i] = 0;
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	/* doit lire **argv (one piece) la stocker dans new et afficher new
	*/
	write(1, "Je suis la 1\n", 13);
	char **new;
	int	status;

	(void)argc;
	new = NULL;
	write(1, "Je suis la 2\n", 13);
	status = read_file(argv, new);
	write(1, "Je suis la 10\n", 14);
	print_table(new);
	write(1, "Je suis la 11\n", 15);
	return (0);
}


/*
i = 0;
nb_line = 5;
if (!(new = (char**)malloc(sizeof(char*) * (nb_line + 1))))
	return (0);
while (argv[1])
{
	new[i] = argv[i];
	i++;
}
new[i] = 0;
*/
