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

int	read_file(char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
