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

/*void		center_points(t_3d_p_tab *p_tab, t_window *win)
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
}*/

void		center_points(t_3d_p_tab *p_tab, t_window *win)
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

int			get_x_min(t_3d_p_tab *p_tab)
{
	int	min;
	int	x;
	int	y;

	min = p_tab->tab[0][0].x;
	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			if (p_tab->tab[y][x].x < min)
				min = p_tab->tab[y][x].x;
			x++;
		}
		y++;
	}
	return (min);
}

int			get_x_max(t_3d_p_tab *p_tab)
{
	int	max;
	int	x;
	int	y;

	max = p_tab->tab[0][0].x;
	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			if (p_tab->tab[y][x].x > max)
				max = p_tab->tab[y][x].x;
			x++;
		}
		y++;
	}
	return (max);
}

int			get_y_min(t_3d_p_tab *p_tab)
{
	int	min;
	int	x;
	int	y;

	min = p_tab->tab[0][0].y;
	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			if (p_tab->tab[y][x].y < min)
				min = p_tab->tab[y][x].y;
			x++;
		}
		y++;
	}
	return (min);
}

int			get_y_max(t_3d_p_tab *p_tab)
{
	int	max;
	int	x;
	int	y;

	max = p_tab->tab[0][0].y;
	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			if (p_tab->tab[y][x].y > max)
				max = p_tab->tab[y][x].y;
			x++;
		}
		y++;
	}
	return (max);
}

void			center_x(t_3d_p_tab *p_tab, int x_min)
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

void			center_y(t_3d_p_tab *p_tab, int y_min)
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

void			rescale(t_3d_p_tab *p_tab, t_window *win, int xtrem[4])
{
	double	w_coef;
	double	h_coef;

	w_coef = (double)win->width / (xtrem[1] - xtrem[0]);
	h_coef = (double)win->height / (xtrem[3] - xtrem[2]);
	if (w_coef < h_coef)
		rescale_w(p_tab, w_coef);
	else
		rescale_h(p_tab, h_coef);
}

void			rescale_w(t_3d_p_tab *p_tab, double w_coef)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = round(p_tab->tab[y][x].x * w_coef);
			p_tab->tab[y][x].y = round(p_tab->tab[y][x].y * w_coef);
			x++;
		}
		y++;
	}
}

void			rescale_h(t_3d_p_tab *p_tab, double h_coef)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = round(p_tab->tab[y][x].x * h_coef);
			p_tab->tab[y][x].y = round(p_tab->tab[y][x].y * h_coef);
			x++;
		}
		y++;
	}
}
