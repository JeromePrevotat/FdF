/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** MLX KEYCODE :
** ESC : 53
** X : 7
** S : 1
** P : 0
** UP_ARROW : 126
** RIGTH_ARROW : 124
** DOWN_ARROW : 125
** LEFT_ARROW : 123
** R : 15
** F : 3
*/

int	fun_list(int keycode, void *window)
{
	if (keycode == 53)
		close_program(window);
	if (keycode == 0)
		draw_all_points(window);
	if (keycode == 1)
		draw_all_segment(window, 0x00FFFFFF);
	if (keycode == 7)
		del_segment(window, 0x00000000);
	if (keycode == 126)
		move_up(window);
	if (keycode == 124)
		move_rigth(window);
	if (keycode == 125)
		move_down(window);
	if (keycode == 123)
		move_left(window);
	if (keycode == 15)
		zoom_in(window);
	if (keycode == 3)
		zoom_out(window);
	if (keycode != 53 && keycode != 0 && keycode != 1 && keycode != 123
		&& keycode != 124 && keycode != 125 && keycode != 126 && keycode != 7
		&& keycode != 15 && keycode != 3)
		get_keycode(keycode);
	return (0);
}

int	close_program(t_window *win)
{
	free_ressources(win);
	ft_putendl("ESC pressed, closing program.");
	exit(0);
	return (0);
}

int	get_keycode(int keycode)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
