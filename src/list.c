/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                  	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		to_lst_start(t_3D_p_list **point_list)
{
	while ((*point_list)->prev != NULL)
		(*point_list) = (*point_list)->prev;
}

void		to_lst_end(t_3D_p_list **point_list)
{
	while ((*point_list)->next != NULL)
		(*point_list) = (*point_list)->next;
}
