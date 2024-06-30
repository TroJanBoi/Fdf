/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:59:53 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/27 14:39:02 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_struct(t_plot **plot)
{
	int	i;

	i = 0;
	while (plot[i] != NULL)
	{
		free(plot[i]);
		i++;
	}
	free(plot);
}

void	ft_close(t_fdf *cs)
{
	mlx_terminate(cs->mlx);
	ft_free(cs->map);
	ft_free_struct(cs->plot);
	exit(EXIT_SUCCESS);
}
