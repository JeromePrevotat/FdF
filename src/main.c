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

int	main(int argc, char **argv)
{
	void		*mlx;
	t_window 	*win1;
	t_3D_p_list	**point_list;
	t_3D_p_tab	*p_tab;

	if (argc == 2)
	{
		if (!(point_list = (t_3D_p_list **)malloc(1 * sizeof(t_3D_p_list *))))
			return (-1);
		*point_list = NULL;
		if (!(p_tab = (t_3D_p_tab *)malloc(1 * sizeof(t_3D_p_tab))))
			return (-1);
		if (parsing_file(argv[1], point_list) != 1)
		{
			ft_putendl("Incorrect File");
			exit(-1);
		}
		//point list filled
		if (!(p_tab->tab = (t_3D_point **)malloc(get_tab_y(point_list) * sizeof(t_3D_point *))))
			return (-1);
		argc = 0;
		while (argc != get_tab_y(point_list))
		{
			if (!(p_tab->tab[argc] = (t_3D_point *)malloc(get_tab_x(point_list) * sizeof(t_3D_point))))
				return (-1);
			argc++;
		}
		p_tab->x_max = get_tab_x(point_list);
		p_tab->y_max = get_tab_y(point_list);
		//assign points in list to tab
		fill_tab(point_list, p_tab);
		free(point_list);
		mlx = mlx_init();
		win1 = init_window(mlx, argv[1], 800, p_tab);
		adapt_coord(p_tab, win1);
		//cart_to_iso(p_tab);
		cart_to_para(p_tab);
		center_points(p_tab, win1);

		//largeur hauteur titre*/
		win1->p_w = mlx_new_window(mlx, win1->width, win1->height, win1->title);

		//fenetre abscisse ordonnee couleur(hex alpha RGB)
		//mlx_pixel_put(mlx, win1->p_w, 200, 200, 0x00FF0000);

		//event clavier
		//window, pointeur fonction, param
		mlx_key_hook(win1->p_w, fun_list, win1);
		draw_all_segment(win1, 0x00FFFFFF);
		mlx_loop(mlx);
	}
	else
	{
		ft_putendl("Usage: ./fdf PathToMyFile");
		exit(-1);
	}
	return (0);
}
