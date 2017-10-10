/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_matrice_x(double **matrice, double coef)
{
	matrice[0][0] = 1;
	matrice[0][1] = 0;
	matrice[0][2] = 0;
	matrice[0][3] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = cos(coef);
	matrice[1][2] = sin(coef);
	matrice[1][3] = 0;
	matrice[2][0] = 0;
	matrice[2][1] = -sin(coef);
	matrice[2][2] = cos(coef);
	matrice[2][3] = 0;
	matrice[3][0] = 0;
	matrice[3][1] = 0;
	matrice[3][2] = 0;
	matrice[3][3] = 1;
}

void	fill_matrice_y(double **matrice, double coef)
{
	matrice[0][0] = cos(coef);
	matrice[0][1] = 0;
	matrice[0][2] = -sin(coef);
	matrice[0][3] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = 1;
	matrice[1][2] = 0;
	matrice[1][3] = 0;
	matrice[2][0] = sin(coef);
	matrice[2][1] = 0;
	matrice[2][2] = cos(coef);
	matrice[2][3] = 0;
	matrice[3][0] = 0;
	matrice[3][1] = 0;
	matrice[3][2] = 0;
	matrice[3][3] = 1;
}

void	fill_matrice_z(double **matrice, double coef)
{
	matrice[0][0] = cos(coef);
	matrice[0][1] = sin(coef);
	matrice[0][2] = 0;
	matrice[0][3] = 0;
	matrice[1][0] = sin(coef);
	matrice[1][1] = cos(coef);
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
