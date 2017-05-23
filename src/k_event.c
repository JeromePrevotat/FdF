/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	fun_list(int keycode, void *window)
{
	if (keycode == 53)
		close_program();
	if (keycode == 35)
		draw_next_point(window);
	if (keycode == 3)
		draw_first_point(window);
	if (keycode == 37)
		draw_last_point(window);
	if (keycode == 0)
		draw_all_point(window);
	/*if (keycode == 126)
		move_up(window);
	if (keycode == 124)
		move_rigth(window);
	if (keycode == 125)
		move_down(window);
	if (keycode == 123)
		move_left(window);*/
	if (keycode != 53 && keycode != 35 && keycode != 3 && keycode != 37 && keycode != 0
		&& keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		get_keycode(keycode);
	return (0);
}

int	close_program()
{
	ft_putendl("ESC pressed, closing program");
	exit(0);
	return (0);
}


int	get_keycode(int keycode)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
