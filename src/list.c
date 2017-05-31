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

t_3D_p_list	*p_lstnew(t_3D_point *p)
{
	t_3D_p_list	*point_3D;

	if (!(point_3D = (t_3D_p_list *)malloc(1 * sizeof(t_3D_p_list))))
		return (NULL);
	point_3D->point = p;
	point_3D->next = NULL;
	point_3D->prev = NULL;
	return (point_3D);
}

void		lst_add_3Dpoint(t_3D_p_list **point_list, t_3D_p_list *point)
{
	if ((*point_list) == NULL && point)
		(*point_list) = point;
	else if ((*point_list) != NULL && point)
	{
		while ((*point_list)->next != NULL)
			(*point_list) = (*point_list)->next;
		(*point_list)->next = point;
		point->prev = (*point_list);
		point->next = NULL;
	}
}
