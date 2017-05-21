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

	if (argc == 2)
	{
		if (parsing_file(argv[1]) != 1)
		{
			ft_putendl("Incorrect File");
			exit(-1);
		}
		mlx = mlx_init();
		ft_putendl("YOLO");
		win1 = init_window(mlx, argv[1], 400, 400);
		//largeur hauteur titre
		win1->p_window = mlx_new_window(mlx, 400, 400, argv[1]);
		//fenetre abscisse ordonnee couleur(hex alpha RGB)
		mlx_pixel_put(mlx, win1->p_window, 200, 200, 0x00FF0000);
		mlx_loop(mlx);
	}
	else
	{
		ft_putendl("Usage: ./fdf PathToMyFile");
		exit(-1);
	}
	return (0);
}
