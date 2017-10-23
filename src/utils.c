/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	del_segment(t_window *win, int color)
{
	draw_all_segment(win, color);
}

void	error(void)
{
	ft_putendl("Incorrect File");
	exit(-1);
}

void	usage(void)
{
	ft_putendl("Usage: ./fdf PathToMyFile");
	exit(-1);
}

void	free_ressources(t_window *win)
{
	if (win != NULL && win->base_tab != NULL)
		free_tab(win->base_tab);
	if (win != NULL && win->p_tab != NULL)
		free_tab(win->p_tab);
	if (win != NULL)
		free(win);
}

void			free_tab(t_3d_p_tab *tab)
{
	int	y;

	y = 0;
	if (tab != NULL)
	{
		while (y != tab->y_max)
		{
			if (tab->tab[y] != NULL)
				free(tab->tab[y]);
			y++;
		}
		free(tab);
	}
}
