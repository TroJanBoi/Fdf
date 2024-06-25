/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:38:09 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/25 22:17:39 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	ft_atoh(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
		return (RED_COLOR);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = i + 2;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 16) + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = (res * 16) + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = (res * 16) + (str[i] - 'A' + 10);
		i++;
	}
	return (res);
}

void	ft_alloc(t_fdf *nbr)
{
	int	i;

	nbr->plot = malloc(sizeof(t_plot *) * (nbr->row + 1));
	if (!nbr->plot)
		return ;
	i = 0;
	while (i < nbr->row)
	{
		nbr->plot[i] = malloc(sizeof(t_plot) * (nbr->col));
		if (!nbr->plot[i])
			return ;
		i++;
	}
	nbr->plot[i] = NULL;
}

int	ft_count_nbr(char *nbr)
{
	int		i;
	char	**result;

	result = ft_split(nbr, ' ');
	i = 0;
	while (result[i] != NULL)
		i++;
	ft_free(result);
	return (i);
}

void	ft_put_pixel(t_fdf *pic, int x, int y, long color)
{
	int	w;
	int	h;

	w = pic->img->width;
	h = pic->img->height;
	if ((x >= 0 && x < w) && (y >= 0 && y < h))
		mlx_put_pixel(pic->img, x, y, (color << 8) + 255);
}
