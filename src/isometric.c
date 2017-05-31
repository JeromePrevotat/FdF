/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		cart_to_iso(t_3D_p_tab *p_tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = (sqrt(2) / 2) * (p_tab->tab[y][x].x - p_tab->tab[y][x].y);
			p_tab->tab[y][x].y = sqrt(2/3) * p_tab->tab[y][x].z + (1 / sqrt(6)) * (p_tab->tab[y][x].x + p_tab->tab[y][x].y);
			/*p_tab->tab[y][x].x = ((p_tab->tab[y][x].x - p_tab->tab[y][x].y) - p_tab->tab[y][x].z);
			p_tab->tab[y][x].y = (((p_tab->tab[y][x].x + p_tab->tab[y][x].y) / 2) - p_tab->tab[y][x].z);*/
			ft_putnbr(p_tab->tab[y][x].x);
			ft_putchar(',');
			ft_putnbr(p_tab->tab[y][x].y);
			ft_putchar(',');
			ft_putnbr(p_tab->tab[y][x].z);
			ft_putchar('\n');
			x++;
		}
		y++;
	}
}
