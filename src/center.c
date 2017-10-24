/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	center_points(t_3d_p_tab *p_tab, t_window *win)
{
	int	xtrem[4];

	xtrem[0] = get_x_min(p_tab);
	xtrem[1] = get_x_max(p_tab);
	xtrem[2] = get_y_min(p_tab);
	xtrem[3] = get_y_max(p_tab);
	if (xtrem[1] - xtrem[0] > win->width || xtrem[3] - xtrem[2] > win->height)
	{
		rescale(p_tab, win, xtrem);
		xtrem[0] = get_x_min(p_tab);
		xtrem[1] = get_x_max(p_tab);
		xtrem[2] = get_y_min(p_tab);
		xtrem[3] = get_y_max(p_tab);
	}
	if (xtrem[0] < 0)
		center_x(p_tab, xtrem[0]);
	if (xtrem[2] < 0)
		center_y(p_tab, xtrem[2]);
}

void	center_x(t_3d_p_tab *p_tab, int x_min)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = p_tab->tab[y][x].x + (-x_min);
			x++;
		}
		y++;
	}
}

void	center_y(t_3d_p_tab *p_tab, int y_min)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].y = p_tab->tab[y][x].y + (-y_min);
			x++;
		}
		y++;
	}
}
