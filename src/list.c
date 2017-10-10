/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		to_lst_start(t_3d_p_list **point_list)
{
	while ((*point_list)->prev != NULL)
		(*point_list) = (*point_list)->prev;
}

void		to_lst_end(t_3d_p_list **point_list)
{
	while ((*point_list)->next != NULL)
		(*point_list) = (*point_list)->next;
}

t_3d_p_list	*p_lstnew(t_3d_point *p)
{
	t_3d_p_list	*point_3d;

	if (!(point_3d = (t_3d_p_list *)malloc(1 * sizeof(t_3d_p_list))))
		return (NULL);
	point_3d->point = p;
	point_3d->next = NULL;
	point_3d->prev = NULL;
	return (point_3d);
}

void		lst_add_3dpoint(t_3d_p_list **point_list, t_3d_p_list *point)
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
