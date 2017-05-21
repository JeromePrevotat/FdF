/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	new_3D_point(t_3D_p_list **p_list, int absc, int ord, int h)
{
	t_3D_point	*point;

	if (!(point = (t_3D_point *)malloc(1 * sizeof(t_3D_point))))
		return (-1);
	point->x = absc;
	point->y = ord;
	point->z = h;
	lst_add_3Dpoint(p_list, p_lstnew(point));
	return (1);
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
	if (*point_list == NULL)
		ft_putendl("point_list NULL");
	if (point == NULL)
		ft_putendl("pointeur point 3D NULL");
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

void		to_lst_start(t_3D_p_list **point_list)
{
	ft_putendl("Entering to_lst_start");
	if ((*point_list) == NULL)
		ft_putendl("NULL");
	while ((*point_list)->prev != NULL)
		(*point_list) = (*point_list)->prev;
	ft_putendl("Exiting to_lst_start");
}
