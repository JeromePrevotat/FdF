/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_x_min(t_3d_p_tab *p_tab)
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

int	get_x_max(t_3d_p_tab *p_tab)
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

int	get_y_min(t_3d_p_tab *p_tab)
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

int	get_y_max(t_3d_p_tab *p_tab)
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
