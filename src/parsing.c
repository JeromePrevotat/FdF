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
	char	*line;

	ft_putendl("Entering parsing_file");
	//init line
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	gnl = -1;
	while (line != NULL)
	{
		ft_putendl("Entering while loop");
		gnl = gnl + get_next_line(fd, &line);
		ft_putendl("gnl succeed");
		parsing_line(line, gnl);
		if (ft_strlen(line) == 0)
			line = NULL;
	}

	return (1);
}

int	parsing_line(char *line, int y)
{
	int		i;
	int		j;
	char	**point_tab;

	i = 0;
	ft_putendl("Entering parsing_line");
	point_tab = ft_strsplit(line, ' ');
	while (point_tab[i])
	{
		j = 0;
		while (point_tab[i][j])
		{
			//new_3D_point(i, y, atoi(&point_tab[i][j]));
			j++;
		}
		i++;
	}
	ft_putnbr(y);
	ft_putstr(" : ");
	ft_putendl(line);
	return (0);
}
