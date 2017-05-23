/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c        	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	draw_next_point(t_window *window)
{
	//mlx_pixel_put(window->mlx_p, window->p_w, 200, 200, 0x00FF0000);
	t_3D_p_list **tmp;

	tmp = window->p_list;
	if ((*(tmp)) == NULL)
	{
		ft_putendl("Point NULL");
		return (0);
	}
	if ((*(tmp)) != NULL)
	{
		if ((*(tmp))->point->z == 0)
			mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x00FFFFFF);
		if ((*(tmp))->point->z > 0 && (*(tmp))->point->z <= 10)
			mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x000000FF);
		if ((*(tmp))->point->z > 10 && (*(tmp))->point->z <= 20)
			mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x0000FF00);
		if ((*(tmp))->point->z > 20)
			mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x00FF0000);
	}
	if ((*(tmp))->next != NULL)
		(*(tmp)) = (*(tmp))->next;
	else
		return (0);
	return (1);
}

int	draw_first_point(t_window *window)
{
	t_3D_p_list **tmp;

	tmp = window->p_list;
	if ((*(tmp)) == NULL)
		ft_putendl("No point to draw");
	if ((*(tmp)) != NULL)
	{
		to_lst_start(tmp);
		mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x00FF0000);
	}
	return (0);
}

int	draw_last_point(t_window *window)
{
	t_3D_p_list **tmp;

	tmp = window->p_list;
	if ((*(tmp)) == NULL)
		ft_putendl("No point to draw");
	if ((*(tmp)) != NULL)
	{
		to_lst_end(tmp);
		mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x00FF0000);
	}
	return (0);
}

int	draw_all_point(t_window *window)
{
	while (draw_next_point(window));
	return (0);
}

int	draw_segment(t_3D_p_list **point_A, t_window *window)
{
	t_3D_p_list **tmp;

	tmp = point_A;
	int to_draw_x;
	int to_draw_y;
	int dx;
	int dy;
	int e;

	if ((*(point_A)) != NULL && (*(point_A))->next != NULL)
	{
		to_draw_x = (*(point_A))->point->x;
		to_draw_y = (*(point_A))->point->y;
		e = (*(point_A))->next->point->x - (*(point_A))->point->x;
		dx = e * 2;
		dy = ((*(point_A))->next->point->y - (*(point_A))->point->y) * 2;
		while (to_draw_x <= (*(point_A))->next->point->x)
		{
			mlx_pixel_put(window->mlx_p, window->p_w, to_draw_x, to_draw_y, 0x00FFFFFF);
			to_draw_x++;
			e = e - dy;
			if (e <= 0)
			{
				to_draw_y++;
				e = e + dx;
			}
		}
		return (1);
	}
	else
		return (0);
}

int	draw_all_seg(t_3D_p_list **point_A, t_window *window)
{
	while (draw_segment(point_A, window))
		*point_A = (*(point_A))->next;
	return (0);
}
