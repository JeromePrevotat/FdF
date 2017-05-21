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

	if (argc == 2)
	{
		if (!(point_list = (t_3D_p_list **)malloc(1 * sizeof(t_3D_p_list *))))
			return (-1);
		*point_list = NULL;
		if (parsing_file(argv[1], point_list) != 1)
		{
			ft_putendl("Incorrect File");
			exit(-1);
		}
		mlx = mlx_init();
		win1 = init_window(mlx, argv[1], 400, 400, point_list);

		//largeur hauteur titre
		win1->p_w = mlx_new_window(mlx, win1->width, win1->height, win1->title);

		//fenetre abscisse ordonnee couleur(hex alpha RGB)
		//mlx_pixel_put(mlx, win1->p_w, 200, 200, 0x00FF0000);

		//event clavier
		//window, pointeur fonction, param
		mlx_key_hook(win1->p_w, fun_list, win1);
		mlx_loop(mlx);
	}
	else
	{
		ft_putendl("Usage: ./fdf PathToMyFile");
		exit(-1);
	}
	return (0);
}
