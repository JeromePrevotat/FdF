/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_window	*init_window(void *mlx_p, char *title, int width, int height, t_3D_p_list **point_list)
{
	t_window	*win;

	if (!(win = (t_window *)malloc(1 * sizeof(t_window))))
		return (NULL);
	ft_memset((void *)win, '\0', sizeof(t_window));
	win->mlx_p = mlx_p;
	win->title = title;
	win->width = width;
	win->height = height;
	win->p_list = point_list;
	win->p_w = NULL;
	return (win);
}

void		center_points(t_3D_p_list **point_list, t_window *win)
{
	t_3D_p_list	*tmp;

	to_lst_start(point_list);
	tmp = *point_list;
	while (tmp != NULL)
	{
		tmp->point->x = (tmp->point->x) + (int)(win->width / 4);
		tmp->point->y = (tmp->point->y) + (int)(win->width / 4);
		tmp = tmp->next;
	}
}
