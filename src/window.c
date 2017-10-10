/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_window	*init_window(void *mlx_p, char *title, int width, t_3d_p_tab *p_tab)
{
	t_window	*win;

	if (!(win = (t_window *)malloc(1 * sizeof(t_window))))
		return (NULL);
	ft_memset((void *)win, '\0', sizeof(t_window));
	win->mlx_p = mlx_p;
	win->title = title;
	win->width = width;
	win->height = width - width / 4;
	win->p_tab = p_tab;
	win->p_w = NULL;
	return (win);
}

void		center_points(t_3d_p_tab *p_tab, t_window *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = p_tab->tab[y][x].x + (int)(win->width / 2);
			p_tab->tab[y][x].y = p_tab->tab[y][x].y + (int)(win->height / 2);
			x++;
		}
		y++;
	}
}
