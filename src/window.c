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

t_window	*init_window(void *mlx_p, char *title, int width, int height)
{
	t_window	*win;

	if (!(win = (t_window *)malloc(1 * sizeof(t_window))))
		return (NULL);
	ft_memset((void *)win, '\0', sizeof(t_window));
	win->mlx_p = mlx_p;
	win->title = title;
	win->width = width;
	win->height = height;
	win->p_window = NULL;
	return (win);
}
