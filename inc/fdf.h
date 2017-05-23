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


typedef struct	s_3D_point
{
	int			x;
	int			y;
	int			z;
}				t_3D_point;

typedef struct	s_3D_p_list
{
	struct s_3D_p_list	*prev;
	struct s_3D_p_list	*next;
	t_3D_point	*point;
}				t_3D_p_list;

typedef struct	s_window
{
	void		*mlx_p;
	char		*title;
	int			width;
	int			height;
	t_3D_p_list **p_list;
	void 		*p_w;
} 				t_window;

//k_event.c
int				fun_list(int keycode, void *param);
int				close_program();
int				get_keycode(int keycode);

//Draw.c
int				draw_next_point(t_window *window);
int				draw_first_point(t_window *window);
int				draw_last_point(t_window *window);
int				draw_all_point(t_window *window);
int				draw_segment(t_3D_p_list **point_A, t_window *window);
int				draw_all_seg(t_3D_p_list **point_A, t_window *window);

//Window.c
t_window		*init_window(void *mlx_p, char *title, int width, int height, t_3D_p_list **point_list);
void			center_points(t_3D_p_list **point_list, t_window *win);

//Parsing.c
int				parsing_file(char *file, t_3D_p_list **point_list);
int				parsing_line(char *line, int y, t_3D_p_list	**point_list);

//Point.c
int				new_3D_point(t_3D_p_list **p_list, int absc, int ord, int h);
t_3D_p_list		*p_lstnew(t_3D_point *p);
void			lst_add_3Dpoint(t_3D_p_list **point_list, t_3D_p_list *point);
void			adapt_coord(t_3D_p_list **point_list, t_window *win);
void			cart_to_iso(t_window *win);

//List.c
void			to_lst_start(t_3D_p_list **point_list);
void			to_lst_end(t_3D_p_list **point_list);

//Move.c
void		move_up(t_window *win);
void		move_down(t_window *win);
void		move_rigth(t_window *win);
void		move_left(t_window *win);

#endif
