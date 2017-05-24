/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c        	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	draw_all_points(t_window *window)
{
	//mlx_pixel_put(window->mlx_p, window->p_w, 200, 200, 0x00FF0000);
	int	x;
	int	y;

	y = 0;
	while (y < window->p_tab->y_max)
	{
		x = 0;
		while (x < window->p_tab->x_max)
		{
			if (window->p_tab->tab[y][x].z == 0)
				mlx_pixel_put(window->mlx_p, window->p_w, window->p_tab->tab[y][x].x, window->p_tab->tab[y][x].y, 0x00FFFFFF);
			if (window->p_tab->tab[y][x].z > 0 && window->p_tab->tab[y][x].z <= 10)
				mlx_pixel_put(window->mlx_p, window->p_w, window->p_tab->tab[y][x].x, window->p_tab->tab[y][x].y, 0x000000FF);
			if (window->p_tab->tab[y][x].z > 10 && window->p_tab->tab[y][x].z <= 20)
				mlx_pixel_put(window->mlx_p, window->p_w, window->p_tab->tab[y][x].x, window->p_tab->tab[y][x].y, 0x0000FF00);
			if (window->p_tab->tab[y][x].z > 20)
				mlx_pixel_put(window->mlx_p, window->p_w, window->p_tab->tab[y][x].x, window->p_tab->tab[y][x].y, 0x00FF0000);
			x++;
		}
		y++;
	}
	return (1);
}

int	draw_segment(t_window *window)
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
	while (y < window->p_tab->y_max)
	{
		x = 0;
		while (x < window->p_tab->x_max - 1)
		{
			to_draw_x = window->p_tab->tab[y][x].x;
			to_draw_y = window->p_tab->tab[y][x].y;
			e = window->p_tab->tab[y][x + 1].x - window->p_tab->tab[y][x].x;
			dx = e * 2;
			dy = (window->p_tab->tab[y][x + 1].y - window->p_tab->tab[y][x].y) * 2;
			while (to_draw_x <= window->p_tab->tab[y][x + 1].x)
			{
				mlx_pixel_put(window->mlx_p, window->p_w, to_draw_x, to_draw_y, 0x00FFFFFF);
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

	//Horizontal Segments
	y = 0;
	while (y < window->p_tab->y_max)
	{
		x = 0;
		while (x < window->p_tab->x_max)
		{
			to_draw_x = window->p_tab->tab[y][x].x;
			to_draw_y = window->p_tab->tab[y][x].y;
			e = window->p_tab->tab[y][x + 1].x - window->p_tab->tab[y][x].x;
			dx = e * 2;
			dy = (window->p_tab->tab[y][x + 1].y - window->p_tab->tab[y][x].y) * 2;
			while (to_draw_x <= window->p_tab->tab[y][x + 1].x)
			{
				mlx_pixel_put(window->mlx_p, window->p_w, to_draw_x, to_draw_y, 0x00FFFFFF);
				to_draw_x++;
				e = e + dy;
				if (e >= 0)
				{
					to_draw_y--;
					e = e + dx;
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

/*int	draw_all_seg(t_3D_p_list **point_A, t_window *window)
{
	while (draw_segment(point_A, window))
		*point_A = (*(point_A))->next;
	return (0);
}*/
