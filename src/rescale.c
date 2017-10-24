/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rescale(t_3d_p_tab *p_tab, t_window *win, int xtrem[4])
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

void	rescale_w(t_3d_p_tab *p_tab, double w_coef)
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

void	rescale_h(t_3d_p_tab *p_tab, double h_coef)
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
