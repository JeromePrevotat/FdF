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

int	parsing_file(char *file, t_3D_p_list **point_list)
{
	int		fd;
	int		gnl;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	gnl = -1;
	if (!(line = (char *)malloc(1 * sizeof(char))))
		return (-1);
	while (gnl != -2)
	{
		gnl = gnl + get_next_line(fd, &line);
		parsing_line(line, gnl, point_list);
		if (ft_strlen(line) == 0)
			gnl = -2;
	}
	to_lst_start(point_list);
	return (1);
}

int	parsing_line(char *line, int y, t_3D_p_list	**point_list)
{
	int		i;
	int		j;
	char	**point_tab;

	i = 0;
	point_tab = ft_strsplit(line, ' ');
	while (point_tab[i] != '\0')
	{
		j = 0;
		while (point_tab[i][j] != '\0')
		{
			//new_3D_point(i, y, atoi(&point_tab[i][j]));
			new_3D_point(point_list, i, y, 0);
			j++;
		}
		i++;
	}
	ft_putnbr(y);
	ft_putstr(" : ");
	ft_putendl(line);
	return (0);
}
