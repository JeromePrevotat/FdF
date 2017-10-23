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
#include <math.h>

#include <stdio.h>

#ifndef _FDF_
# define _FDF_
# define TRUE 1
# define FALSE 0
# define ERROR -1


typedef struct	s_3d_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_3d_point;

typedef struct	s_3d_p_list
{
	struct s_3d_p_list	*prev;
	struct s_3d_p_list	*next;
	t_3d_point	*point;
}				t_3d_p_list;

typedef struct	s_3d_p_tab
{
	int			x_max;
	int			y_max;
	t_3d_point	**tab;
}				t_3d_p_tab;

typedef struct	s_window
{
	void		*mlx_p;
	char		*title;
	int			width;
	int			height;
	int			zoom;
	t_3d_p_tab	*p_tab;
	void 		*p_w;
} 				t_window;

typedef struct	s_seg_arg
{
	int dx;
	int dy;
	int to_draw_x;
	int to_draw_y;
	int xinc;
	int yinc;
}				t_seg_arg;

//K_event.c
int				fun_list(int keycode, void *param);
int				close_program();
int				get_keycode(int keycode);

//Draw.c
int				draw_all_points(t_window *window);

//Segment.c
void			draw_all_segment(t_window *win, int color);
void			draw_segment(t_window *win, t_3d_point point_a, t_3d_point point_b, int color);
int				draw_h_segment(t_window *win, t_seg_arg *seg_arg, int color);
int				draw_v_segment(t_window *win, t_seg_arg *seg_arg, int color);

//Window.c
t_window		*init_window(void *mlx_p, char *title, int width, t_3d_p_tab *p_tab);
void			center_points(t_3d_p_tab *p_tab, t_window *win);
int				get_x_min(t_3d_p_tab *p_tab);
int				get_x_max(t_3d_p_tab *p_tab);
int				get_y_min(t_3d_p_tab *p_tab);
int				get_y_max(t_3d_p_tab *p_tab);
void			center_x(t_3d_p_tab *p_tab, int x_min);
void			center_y(t_3d_p_tab *p_tab, int y_min);
void			rescale(t_3d_p_tab *p_tab, t_window *win, int xtrem[4]);
void			rescale_w(t_3d_p_tab *p_tab, double w_coef);
void			rescale_h(t_3d_p_tab *p_tab, double h_coef);

//Parsing.c
int				parsing_file(char *file, t_3d_p_list **point_list);
int				parsing_line(char *line, int y, t_3d_p_list	**point_list);

//Point.c
int				new_3d_point(t_3d_p_list **p_list, int absc, int ord, int h);
void			adapt_coord(t_3d_p_tab *p_tab, t_window *win);
void			cart_to_para(t_3d_p_tab *p_tab);

//List.c
void			to_lst_start(t_3d_p_list **point_list);
void			to_lst_end(t_3d_p_list **point_list);
void			lst_add_3dpoint(t_3d_p_list **point_list, t_3d_p_list *point);
t_3d_p_list		*p_lstnew(t_3d_point *p);

//Tab.c
int				get_tab_x(t_3d_p_list **p_list);
int				get_tab_y(t_3d_p_list **p_list);
int				fill_tab(t_3d_p_list **p_list, t_3d_p_tab *p_tab);

//Isometric.c
void			cart_to_iso(t_3d_p_tab *p_tab);

//Matrice.c
double			**init_matrice(double angle, char a);
void			select_matrix(double **matrice, double angle, char a);
void			fill_matrice_s(double **matrice, double coef);
void			apply_matrice(double **matrice, t_3d_p_tab *p_tab);

//Projection.c
void			fill_matrice_ortho(double **matrice, double coef);
void			fill_matrice_iso(double **matrice, double coef);

//Rotation.c
void			fill_matrice_x(double **matrice, double coef);
void			fill_matrice_y(double **matrice, double coef);
void			fill_matrice_z(double **matrice, double coef);

//Move.c
void			move_up(t_window *win);
void			move_down(t_window *win);
void			move_rigth(t_window *win);
void			move_left(t_window *win);

//Zoom.c
void			zoom_in(t_window *win);
void			zoom_out(t_window *win);

//Utils.c
void			del_segment(t_window *window, int color);
void			error(void);
void			usage(void);

#endif
