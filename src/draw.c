/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	draw_all_points(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->p_tab->y_max)
	{
		x = 0;
		while (x < window->p_tab->x_max)
		{
			mlx_pixel_put(window->mlx_p, window->p_w,
				window->p_tab->tab[y][x].x, window->p_tab->tab[y][x].y,
				window->p_tab->tab[y][x].color);
			x++;
		}
		y++;
	}
	return (1);
}
