/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	cart_to_iso(t_3d_p_tab *p_tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = (p_tab->tab[y][x].x - p_tab->tab[y][x].y);
			p_tab->tab[y][x].y = (((p_tab->tab[y][x].x
				+ p_tab->tab[y][x].y) / 2) - p_tab->tab[y][x].z);
			x++;
		}
		y++;
	}
}
