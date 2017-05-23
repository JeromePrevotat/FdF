/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


void		move_up(t_window *win)
{
	t_3D_p_list	**tmp;

	to_lst_start(win->p_list);
	tmp = win->p_list;
	while ((*tmp)->next != NULL)
	{
		(*tmp)->point->y = ((*tmp)->point->y) + (int)(win->width / 4);
		(*tmp) = (*tmp)->next;
	}
}

void		move_down(t_window *win)
{
	t_3D_p_list	**tmp;

	to_lst_start(win->p_list);
	tmp = win->p_list;
	while ((*tmp) != NULL)
	{
		(*tmp)->point->y = ((*tmp)->point->y) - (int)(win->width / 4);
		(*tmp) = (*tmp)->next;
	}
}

void		move_rigth(t_window *win)
{
	t_3D_p_list	**tmp;

	to_lst_start(win->p_list);
	tmp = win->p_list;
	while ((*tmp) != NULL)
	{
		(*tmp)->point->x = ((*tmp)->point->x) + (int)(win->width / 4);
		(*tmp) = (*tmp)->next;
	}
}

void		move_left(t_window *win)
{
	t_3D_p_list	**tmp;

	to_lst_start(win->p_list);
	tmp = win->p_list;
	while ((*tmp) != NULL)
	{
		(*tmp)->point->x = ((*tmp)->point->x) - (int)(win->width / 4);
		(*tmp) = (*tmp)->next;
	}
}
