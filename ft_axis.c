/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:43:56 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/25 22:18:26 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_find_axis(t_fdf *ax)
{
	int		row;
	int		col;
	int		max_col;

	row = 0;
	max_col = ft_count_nbr(ax->map[row]);
	while (ax->map[row])
	{
		col = ft_count_nbr(ax->map[row]);
		if (col != max_col)
			ft_error_sq("Found wrong line length. Exiting.\n", 2, ax);
		else if (max_col == 0 && row == 0 && col == 0)
			ft_error("No data found.\n", 2);
		row++;
	}
	ax->col = max_col;
	ax->row = row;
}
