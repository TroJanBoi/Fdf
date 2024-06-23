/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:43:37 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/23 22:08:57 by pesrisaw         ###   ########.fr       */
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

	printf("start set color \n");
	c = 0;
	if (color[1] != NULL)
		nbr->plot[i][j].c = ft_atoh(color[1]);
	else
		nbr->plot[i][j].c = WHITE_COLOR;
	c = nbr->plot[i][j].c;
	printf("done set color\n");
	return (c);
}

void	ft_find_color(t_fdf *nbr, char *str)
{
	char	**result;
	char	**s;
	char	*line;

	printf("start color\n");
	nbr->fd = open(str, O_RDONLY);
	nbr->i = 0;
	while (nbr->i < nbr->row)
	{
		line = get_next_line(nbr->fd);
		if (!line)
			break ;
		result = ft_split(line, ' ');
		nbr->j = 0;
		printf("start loop color\n");
		while (nbr->j < nbr->col)
		{
			if (result[nbr->j] != NULL)
			{
				s = ft_split(result[nbr->j], ',');
				if (s)
				{
					nbr->plot[nbr->i][nbr->j].c = set_color(s, nbr, nbr->i, nbr->j);
					ft_free(s);
				}
			}
			else
				nbr->plot[nbr->i][nbr->j].c = WHITE_COLOR;
			nbr->j++;
		}
		printf("loop color\n");
		if (result)
			ft_free(result);
		free(line);
		nbr->i++;
	}
	close(nbr->fd);
	printf("done color\n");
}
