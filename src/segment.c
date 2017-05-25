/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void draw_all_segment(t_window *win)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (x < win->p_tab->x_max - 1)
	{
		draw_segment(win, win->p_tab->tab[y][x], win->p_tab->tab[y][x + 1]);
		x++;
	}
	while (y < win->p_tab->y_max - 1)
	{
		draw_segment(win, win->p_tab->tab[y][x], win->p_tab->tab[y + 1][x]);
		y++;
	}
}

void draw_segment(t_window *win, t_3D_point point_a, t_3D_point point_b)
{
	t_seg_arg	*seg_arg;

	if (!(seg_arg = (t_seg_arg *)malloc(1 * sizeof(seg_arg))))
		return ;
	seg_arg->to_draw_x = point_a.x;
	seg_arg->to_draw_y = point_a.y;
	seg_arg->dx = point_b.x - point_a.x;
	seg_arg->dy = point_b.y - point_a.y;
	if (seg_arg->dx > 0)
		seg_arg->xinc = 1;
	else
		seg_arg->xinc = -1;
	if (seg_arg->dy > 0)
		seg_arg->yinc = 1;
	else
		seg_arg->yinc = -1;
	seg_arg->dx = abs(seg_arg->dx);
	seg_arg->dy = abs(seg_arg->dy);
	//Segment Horizontal
	if (seg_arg->dx > seg_arg->dy)
		draw_h_segment(win, seg_arg);
	//Segment vertical
	else
		draw_v_segment(win, seg_arg);
	if (seg_arg != NULL)
		free(seg_arg);
}

void draw_h_segment(t_window *win, t_seg_arg *seg_arg)
{
	int i;
	int cumul;

	cumul = seg_arg->dx / 2;
	i = 1;
	while (i <= seg_arg->dx)
	{
		seg_arg->to_draw_x = seg_arg->to_draw_x + seg_arg->xinc;
		cumul = cumul + seg_arg->dy;
		if (cumul >= seg_arg->dx)
		{
			cumul = cumul - seg_arg->dx;
			seg_arg->to_draw_y = seg_arg->to_draw_y + seg_arg->yinc;
		}
		mlx_pixel_put(win->mlx_p, win->p_w, seg_arg->to_draw_x, seg_arg->to_draw_y, 0x0000FF00);
		i++;
	}
}

void draw_v_segment(t_window *win, t_seg_arg *seg_arg)
{
	int i;
	int cumul;

	cumul = seg_arg->dy / 2;
	i = 1;
	while (i <= seg_arg->dy)
	{
		seg_arg->to_draw_y = seg_arg->to_draw_y + seg_arg->yinc ;
		cumul = cumul + seg_arg->dx ;
		if (cumul >= seg_arg->dy)
		{
			cumul = cumul - seg_arg->dy;
			seg_arg->to_draw_x = seg_arg->to_draw_x + seg_arg->xinc;
		}
		mlx_pixel_put(win->mlx_p, win->p_w, seg_arg->to_draw_x, seg_arg->to_draw_y, 0x0000FF00);
		i++;
	}
}

int	del_segment(t_window *win)
{
	int	dx;
	int	dy;
	int	e;
	int	to_draw_x;
	int	to_draw_y;
	int x;
	int y;

	//Vertical Segments
	y = 0;
	while (y < win->p_tab->y_max)
	{
		x = 0;
		while (x < win->p_tab->x_max)
		{
			to_draw_x = win->p_tab->tab[y][x].x;
			to_draw_y = win->p_tab->tab[y][x].y;
			e = win->p_tab->tab[y][x + 1].x - win->p_tab->tab[y][x].x;
			dx = e * 2;
			dy = (win->p_tab->tab[y][x + 1].y - win->p_tab->tab[y][x].y) * 2;
			while (to_draw_x <= win->p_tab->tab[y][x + 1].x)
			{
				mlx_pixel_put(win->mlx_p, win->p_w, to_draw_x, to_draw_y, 0x00000000);
				to_draw_x++;
				e = e - dy;
				if (e <= 0)
				{
					to_draw_y++;
					e = e + dx;
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}
