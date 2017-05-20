/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	parsing_file(char *file)
{
	int		fd;
	int		gnl;
	int		i;
	char	*line;

	(void)i;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	gnl = -1;
	while (ft_strlen(line) > 0)
	{
		gnl = gnl + get_next_line(fd, &line);
		parsing_line(line, gnl);
	}

	return (1);
}

int	parsing_line(char *line, int y)
{
	ft_putnbr(y);
	ft_putstr(" : ");
	ft_putendl(line);
	return (0);
}
