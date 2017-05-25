/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	new_3D_point(t_3D_p_list **p_list, int absc, int ord, int h)
{
	t_3D_point	*point;

	if (!(point = (t_3D_point *)malloc(1 * sizeof(t_3D_point))))
		return (-1);
	point->x = absc;
	point->y = ord;
	point->z = h;
	lst_add_3Dpoint(p_list, p_lstnew(point));
	return (1);
}

t_3D_p_list	*p_lstnew(t_3D_point *p)
{
	t_3D_p_list	*point_3D;

	if (!(point_3D = (t_3D_p_list *)malloc(1 * sizeof(t_3D_p_list))))
		return (NULL);
	point_3D->point = p;
	point_3D->next = NULL;
	point_3D->prev = NULL;
	return (point_3D);
}

void		lst_add_3Dpoint(t_3D_p_list **point_list, t_3D_p_list *point)
{
	if ((*point_list) == NULL && point)
		(*point_list) = point;
	else if ((*point_list) != NULL && point)
	{
		while ((*point_list)->next != NULL)
			(*point_list) = (*point_list)->next;
		(*point_list)->next = point;
		point->prev = (*point_list);
		point->next = NULL;
	}
}

void		adapt_coord(t_3D_p_tab *p_tab, t_window *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			p_tab->tab[y][x].x = (int)(((3 * win->width) / 100) * (p_tab->tab[y][x].x));
			p_tab->tab[y][x].y = (int)(((3 * win->height) / 100) * (p_tab->tab[y][x].y));
			x++;
		}
		y++;
	}
}

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
			p_tab->tab[y][x].x = (p_tab->tab[y][x].x - p_tab->tab[y][x].y) - p_tab->tab[y][x].z;
			p_tab->tab[y][x].y = ((p_tab->tab[y][x].x + p_tab->tab[y][x].y) / 2) - p_tab->tab[y][x].z;
			x++;
		}
		y++;
	}
}

void		cart_to_para(t_3D_p_tab *p_tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			if (p_tab->tab[y][x].z != 0)
			{
				p_tab->tab[y][x].x = (int)(p_tab->tab[y][x].x * p_tab->tab[y][x].z)/9;
				p_tab->tab[y][x].y = (int)(p_tab->tab[y][x].y * p_tab->tab[y][x].z)/9;
			}
			x++;
		}
		y++;
	}
}
