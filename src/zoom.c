/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void zoom_in(t_window *win)
{
	int	x;
	int	y;
	static int	actual_zoom = 0;
	
	del_segment(win, 0x00000000);
	y = 0;
	while (y < win->p_tab->y_max)
	{
		x = 0;
		while (x < win->p_tab->x_max)
		{
			win->p_tab->tab[y][x].x = (int)(win->p_tab->tab[y][x].x
				+ ((win->p_tab->tab[y][x].x * 5) / 100));
			win->p_tab->tab[y][x].y = (int)(win->p_tab->tab[y][x].y
				+ ((win->p_tab->tab[y][x].y * 5) / 100));
			x++;
		}
		y++;
	}
	draw_all_segment(win, 0x00FFFFFF);
}

void zoom_out(t_window *win)
{
	int	x;
	int	y;

	del_segment(win, 0x00000000);
	y = 0;
	while (y < win->p_tab->y_max)
	{
		x = 0;
		while (x < win->p_tab->x_max)
		{
			win->p_tab->tab[y][x].x = (int)(win->p_tab->tab[y][x].x
				- ((win->p_tab->tab[y][x].x * 5) / 100));
			win->p_tab->tab[y][x].y = (int)(win->p_tab->tab[y][x].y
				- ((win->p_tab->tab[y][x].y * 5) / 100));
			x++;
		}
		y++;
	}
	draw_all_segment(win, 0x00FFFFFF);
}
