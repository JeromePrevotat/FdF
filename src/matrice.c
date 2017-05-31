/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	**init_matrice(double coef, char a)
{
	double	**matrice;
	int		x;

	if (!(matrice = (double **)malloc(3 * sizeof(double *))))
		return (NULL);
	x = 0;
	while (x < 4)
	{
		if (!(matrice[x] = (double *)malloc(3 * sizeof(double))))
			return (NULL);
		x++;
	}
	select_matrix(matrice, coef, a);
	return (matrice);
}

void	select_matrix(double **matrice, double coef, char a)
{
	if (a == 'x')
		fill_matrice_x(matrice, coef);
	if (a == 'y')
		fill_matrice_y(matrice, coef);
	if (a == 'z')
		fill_matrice_z(matrice, coef);
	if (a == 's')
		fill_matrice_s(matrice, coef);
	if (a == 'o')
		fill_matrice_ortho(matrice, coef);
	if (a == 'i')
		fill_matrice_iso(matrice, coef);
	else
		return ;
}

void	fill_matrice_s(double **matrice, double coef)
{
	matrice[0][0] = coef;
	matrice[0][1] = 0;
	matrice[0][2] = 0;
	matrice[0][3] = 0;

	matrice[1][0] = 0;
	matrice[1][1] = coef;
	matrice[1][2] = 0;
	matrice[1][3] = 0;

	matrice[2][0] = 0;
	matrice[2][1] = 0;
	matrice[2][2] = 1;
	matrice[2][3] = 0;

	matrice[3][0] = 0;
	matrice[3][1] = 0;
	matrice[3][2] = 0;
	matrice[3][3] = 1;
}

void	apply_matrice(double **matrice, t_3D_p_tab *p_tab)
{
	double w;
	int x;
	int y;

	y = 0;
	while (y < p_tab->y_max)
	{
		x = 0;
		while (x < p_tab->x_max)
		{
			w = 1;
			ft_putnbr(p_tab->tab[y][x].x);
			ft_putchar(',');
			ft_putnbr(p_tab->tab[y][x].y);
			ft_putchar(',');
			ft_putnbr(p_tab->tab[y][x].z);
			ft_putstr(" // ");
			p_tab->tab[y][x].x = round(p_tab->tab[y][x].x * matrice[0][0] + p_tab->tab[y][x].x * matrice[0][1] + p_tab->tab[y][x].x * matrice[0][2] + p_tab->tab[y][x].x * matrice[0][3]);
			p_tab->tab[y][x].y = round(p_tab->tab[y][x].y * matrice[1][0] + p_tab->tab[y][x].y * matrice[1][1] + p_tab->tab[y][x].y * matrice[1][2] + p_tab->tab[y][x].y * matrice[1][3]);
			p_tab->tab[y][x].z = round(p_tab->tab[y][x].z * matrice[2][0] + p_tab->tab[y][x].z * matrice[2][1] + p_tab->tab[y][x].z * matrice[2][2] + p_tab->tab[y][x].z * matrice[2][3]);
			w = round(w * matrice[3][0] + w * matrice[3][1] + w * matrice[3][2] + w * matrice[3][3]);
			if (w != 1 && w != 0)
			{
				p_tab->tab[y][x].x = round(p_tab->tab[y][x].x / w);
				p_tab->tab[y][x].y = round(p_tab->tab[y][x].y / w);
				p_tab->tab[y][x].z = round(p_tab->tab[y][x].z / w);
			}
			ft_putnbr(p_tab->tab[y][x].x);
			ft_putchar(',');
			ft_putnbr(p_tab->tab[y][x].y);
			ft_putchar(',');
			ft_putnbr(p_tab->tab[y][x].z);
			ft_putchar('\n');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
