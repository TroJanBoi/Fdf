/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:41:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/23 22:37:19 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	ft_drawline(t_fdf *nbr)
{
	nbr->i = 0;
	printf("start\n");
	printf("col : %d\n", nbr->col);
	printf("row : %d\n", nbr->row);
	while (nbr->i < nbr->row)
	{
		nbr->j = 0;
		while (nbr->j < nbr->col)
		{
			if (nbr->i < nbr->row - 1)
				ft_dda(nbr->plot[nbr->i][nbr->j], nbr->plot[nbr->i + 1][nbr->j], nbr);
			if (nbr->j < nbr->col - 1)
				ft_dda(nbr->plot[nbr->i][nbr->j], nbr->plot[nbr->i][nbr->j + 1], nbr);
			nbr->j++;
		}
		nbr->i++;
	}
	printf("end draw\n");
}

void	ft_dda(t_plot start, t_plot end, t_fdf *pic)
{
	t_fdf	lup;
	float	xin;
	float	yin;

	lup.dx = end.x - start.x;
	lup.dy = end.y - start.y;
	if (ft_abs(lup.dx) > ft_abs(lup.dy))
		lup.steps = ft_abs(lup.dx);
	else
		lup.steps = ft_abs(lup.dy);
	xin = lup.dx / lup.steps;
	yin = lup.dy / lup.steps;
	lup.i = 0;
	lup.tmp_x = start.x;
	lup.tmp_y = start.y;
	while (lup.i < lup.steps)
	{
		lup.tmp_x = lup.tmp_x + xin;
		lup.tmp_y = lup.tmp_y + yin;
		ft_put_pixel(pic, (int)lup.tmp_x, (int)lup.tmp_y, start.c);
		lup.i++;
	}
}
