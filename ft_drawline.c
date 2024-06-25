/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:41:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/25 16:34:17 by pesrisaw         ###   ########.fr       */
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
	while (nbr->i < nbr->row)
	{
		nbr->j = 0;
		while (nbr->j < nbr->col)
		{
			if (nbr->i < nbr->row - 1)
				ft_dda(nbr->plot[nbr->i][nbr->j], \
				nbr->plot[nbr->i + 1][nbr->j], nbr);
			if (nbr->j < nbr->col - 1)
				ft_dda(nbr->plot[nbr->i][nbr->j], \
				nbr->plot[nbr->i][nbr->j + 1], nbr);
			nbr->j++;
		}
		nbr->i++;
	}
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
		ft_put_pixel(pic, (lup.tmp_x + (float)(WIDTH / 2)) - \
		((float)(pic->col / 2) * (pic->radio * 0.5)) + 200, \
		(lup.tmp_y + (float)(HEIGHT / 2)) - ((float)(pic->row / 2) * \
		(pic->radio * 0.5)), start.c);
		lup.i++;
	}
}
