/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:43:37 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/24 17:50:06 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

long	set_color(char **color, t_fdf *nbr, int i, int j)
{
	long	c;

	c = 0;
	if (color[1] != NULL)
		nbr->plot[i][j].c = ft_atoh(color[1]);
	else
		nbr->plot[i][j].c = WHITE_COLOR;
	c = nbr->plot[i][j].c;
	return (c);
}

void	ft_find_color(t_fdf *n)
{
	char	**result;

	n->i = 0;
	while (n->i < n->row)
	{
		result = ft_split(n->map[n->i], ' ');
		n->j = 0;
		while (n->j < n->col)
		{
			if (result[n->j] != NULL)
			{
				n->tmp = ft_split(result[n->j], ',');
				if (n->tmp)
				{
					n->plot[n->i][n->j].c = set_color(n->tmp, n, n->i, n->j);
					ft_free(n->tmp);
				}
			}
			else
				n->plot[n->i][n->j].c = WHITE_COLOR;
			n->j++;
		}
		ft_free(result);
		n->i++;
	}
}
