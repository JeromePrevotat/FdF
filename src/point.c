/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		new_3d_point(t_3d_p_list **p_list, int absc, int ord, int h)
{
	t_3d_point	*point;

	if (!(point = (t_3d_point *)malloc(1 * sizeof(t_3d_point))))
		return (-1);
	point->x = absc;
	point->y = ord;
	point->z = h;
	if (h > 0)
		point->color = 0x00FF0000;
	else
		point->color = 0x00FFFFFF;
	lst_add_3dpoint(p_list, p_lstnew(point));
	return (1);
}

void	adapt_coord(t_3d_p_tab *p_tab, t_window *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = (int)(((3 * win->width) / 100)
				* (p_tab->tab[y][x].x));
			p_tab->tab[y][x].y = (int)(((3 * win->height) / 100)
				* (p_tab->tab[y][x].y));

			p_tab->tab[y][x].z = (int)(((3 * win->width) / 100)
				* (p_tab->tab[y][x].z));
			x++;
		}
		y++;
	}
}

void	cart_to_para(t_3d_p_tab *p_tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			if (p_tab->tab[y][x].z != 0)
			{
				p_tab->tab[y][x].x = (int)(p_tab->tab[y][x].x
					* p_tab->tab[y][x].z) / 9;
				p_tab->tab[y][x].y = (int)(p_tab->tab[y][x].y
					* p_tab->tab[y][x].z) / 9;
			}
			x++;
		}
		y++;
	}
}
