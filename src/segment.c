/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	draw_seg_x(t_window *win, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->p_tab->y_max)
	{
		x = 0;
		while (x < win->p_tab->x_max - 1)
		{
			draw_segment(win, win->p_tab->tab[y][x], win->p_tab->tab[y][x + 1],
				color);
			x++;
		}
		y++;
	}
}

static void	draw_seg_y(t_window *win, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->p_tab->y_max - 1)
	{
		x = 0;
		while (x < win->p_tab->x_max)
		{
			draw_segment(win, win->p_tab->tab[y][x], win->p_tab->tab[y + 1][x],
				color);
			x++;
		}
		y++;
	}
}

void	draw_all_segment(t_window *win, int color)
{
	draw_seg_x(win, color);
	draw_seg_y(win, color);
}

void	draw_segment(t_window *win, t_3d_point point_a, t_3d_point point_b,
		int color)
{
	t_seg_arg	*seg_arg;

	if (!(seg_arg = (t_seg_arg *)malloc(1 * sizeof(t_seg_arg))))
		return (-1);
	seg_arg->to_draw_x = point_a.x;
	seg_arg->to_draw_y = point_a.y;
	seg_arg->dx = point_b.x - point_a.x;
	seg_arg->dy = point_b.y - point_a.y;
	mlx_pixel_put(win->mlx_p, win->p_w, point_a.x, point_a.y, color);
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
	if (seg_arg->dx > seg_arg->dy)
		draw_h_segment(win, seg_arg, color);
	else
		draw_v_segment(win, seg_arg, color);
	if (seg_arg != NULL)
		free(seg_arg);
}

int		draw_h_segment(t_window *win, t_seg_arg *seg_arg, int color)
{
	int i;
	int e;

	if (seg_arg == NULL)
		return (-1);
	e = seg_arg->dx / 2;
	i = 1;
	while (i <= seg_arg->dx)
	{
		seg_arg->to_draw_x = seg_arg->to_draw_x + seg_arg->xinc;
		e = e + seg_arg->dy;
		if (e >= seg_arg->dx)
		{
			e = e - seg_arg->dx;
			seg_arg->to_draw_y = seg_arg->to_draw_y + seg_arg->yinc;
		}
		mlx_pixel_put(win->mlx_p, win->p_w, seg_arg->to_draw_x,
			seg_arg->to_draw_y, color);
		i++;
	}
	return (1);
}

int		draw_v_segment(t_window *win, t_seg_arg *seg_arg, int color)
{
	int i;
	int e;

	if (seg_arg == NULL)
		return (-1);
	e = seg_arg->dy / 2;
	i = 1;
	while (i <= seg_arg->dy)
	{
		seg_arg->to_draw_y = seg_arg->to_draw_y + seg_arg->yinc;
		e = e + seg_arg->dx;
		if (e >= seg_arg->dy)
		{
			e = e - seg_arg->dy;
			seg_arg->to_draw_x = seg_arg->to_draw_x + seg_arg->xinc;
		}
		mlx_pixel_put(win->mlx_p, win->p_w, seg_arg->to_draw_x,
			seg_arg->to_draw_y, color);
		i++;
	}
	return (1);
}
