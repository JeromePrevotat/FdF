/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_tab_x(t_3d_p_list **p_list)
{
	int	x_max;

	x_max = 0;
	to_lst_start(p_list);
	while ((*(p_list))->next != NULL)
	{
		if ((*(p_list))->point->x > x_max)
			x_max = (*(p_list))->point->x;
		(*(p_list)) = (*(p_list))->next;
	}
	return (x_max + 1);
}

int	get_tab_y(t_3d_p_list **p_list)
{
	int	y_max;

	y_max = 0;
	to_lst_start(p_list);
	while ((*(p_list))->next != NULL)
	{
		if ((*(p_list))->point->y > y_max)
			y_max = (*(p_list))->point->y;
		(*(p_list)) = (*(p_list))->next;
	}
	return (y_max + 1);
}

int	fill_tab(t_3d_p_list **p_list, t_3d_p_tab *p_tab)
{
	t_3d_p_list	**tmp;
	int			x;
	int			y;

	to_lst_start(p_list);
	tmp = p_list;
	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x] = *(*(tmp))->point;
			if ((*(tmp))->next != NULL)
				(*(tmp)) = (*(tmp))->next;
			x++;
		}
		y++;
	}
	return (1);
}
