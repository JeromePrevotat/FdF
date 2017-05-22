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
		ft_putendl("All points are draw");
	if ((*(tmp)) != NULL)
		mlx_pixel_put(window->mlx_p, window->p_w, (*(tmp))->point->x, (*(tmp))->point->y, 0x00FF0000);
	if ((*(tmp)) != NULL)
		(*(tmp)) = (*(tmp))->next;
	return (0);
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
