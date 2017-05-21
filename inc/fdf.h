/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2017/05/20 21:48:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef _FDF_
# define _FDF_

typedef struct	s_window
{
	char		*title;
	int			width;
	int			height;
} 				t_window;

typedef struct	s_3D_point
{
	int			x;
	int			y;
	int			z;
}				t_3D_point;

//Parsing.c
int				parsing_file(char *file);
int				parsing_line(char *line, int y);

//Graph.c
t_3D_point 		*new_3D_point(int x, int y, int z);

#endif
