/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:29:43 by jprevota          #+#    #+#             */
/*   Updated: 2016/11/15 16:18:37 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fill_matrice_ortho(double **matrice, double coef)
{
	(void)coef;
	matrice[0][0] = 1;
	matrice[0][1] = 0;
	matrice[0][2] = 0;
	matrice[0][3] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = 1;
	matrice[1][2] = 0;
	matrice[1][3] = 0;
	matrice[2][0] = 0;
	matrice[2][1] = 0;
	matrice[2][2] = 0;
	matrice[2][3] = 0;
	matrice[3][0] = 0;
	matrice[3][1] = 0;
	matrice[3][2] = 0;
	matrice[3][3] = 1;
}

void	fill_matrice_iso(double **matrice, double coef)
{
	(void)coef;
	matrice[0][0] = (1 / sqrt(6)) * sqrt(3);
	matrice[0][1] = 0;
	matrice[0][2] = (1 / sqrt(6)) * (-sqrt(3));
	matrice[0][3] = 0;
	matrice[1][0] = 1 / sqrt(6);
	matrice[1][1] = (1 / sqrt(6)) * 2;
	matrice[1][2] = 1 / sqrt(6);
	matrice[1][3] = 0;
	matrice[2][0] = (1 / sqrt(6)) * sqrt(2);
	matrice[2][1] = (1 / sqrt(6)) * (-sqrt(2));
	matrice[2][2] = (1 / sqrt(6)) * sqrt(2);
	matrice[2][3] = 0;
	matrice[3][0] = 0;
	matrice[3][1] = 0;
	matrice[3][2] = 0;
	matrice[3][3] = 1;
}
