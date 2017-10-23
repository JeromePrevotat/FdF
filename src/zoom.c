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

t_3d_p_tab	*ptab_cpy(t_3d_p_list **list, t_window *win)
{
	t_3d_p_tab	*new;
	int			y;

	if (!(new = (t_3d_p_tab *)malloc(1 * sizeof(t_3d_p_tab))))
		return (NULL);
	if (!(new->tab = (t_3d_point **)malloc(get_tab_y(list) * sizeof(t_3d_point *))))
		return (NULL);
	new->x_max = get_tab_x(list);
	new->y_max = get_tab_y(list);
	y = 0;
	while (y != new->y_max)
	{
		if (!(new->tab[y] = (t_3d_point *)malloc(new->x_max * sizeof(t_3d_point))))
			return (NULL);
		y++;
	}
	fill_tab(list, new);
	adapt_coord(new, win);
	cart_to_iso(new);
	center_points(new, win);
	return (new);
}

void zoom_in(t_window *win)
{
	int	x;
	int	y;

	del_segment(win, 0x00000000);
	win->zoom = win->zoom + win->zoom_rate;
	printf("ZOOM : %d%%\n", win->zoom);
	y = 0;
	while (y < win->p_tab->y_max)
	{
		x = 0;
		while (x < win->p_tab->x_max)
		{
			win->p_tab->tab[y][x].x =
				(int)(win->base_tab->tab[y][x].x + ((win->zoom - 100) * win->base_tab->tab[y][x].x / 100));
			win->p_tab->tab[y][x].y =
				(int)(win->base_tab->tab[y][x].y + ((win->zoom - 100) * win->base_tab->tab[y][x].y / 100));
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

	if (win->zoom == 100)
		return ;
	win->zoom = win->zoom - win->zoom_rate;
	printf("ZOOM : %d%%\n", win->zoom);
	del_segment(win, 0x00000000);
	y = 0;
	while (y < win->p_tab->y_max)
	{
		x = 0;
		while (x < win->p_tab->x_max)
		{
			win->p_tab->tab[y][x].x =
				(int)(win->base_tab->tab[y][x].x + ((win->zoom - 100) * win->base_tab->tab[y][x].x / 100));
			win->p_tab->tab[y][x].y =
				(int)(win->base_tab->tab[y][x].y + ((win->zoom - 100) * win->base_tab->tab[y][x].y / 100));
			x++;
		}
		y++;
	}
	draw_all_segment(win, 0x00FFFFFF);
}
