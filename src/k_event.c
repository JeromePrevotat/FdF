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
		close_program(53, window);
	if (keycode == 35)
		draw_next_point(window);
	return (0);
}

int	close_program(int keycode, void *window)
{
	(void)window;
	(void)keycode;
	ft_putendl("ESC pressed, closing program");
	exit(0);
	return (0);
}
