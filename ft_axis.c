/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:43:56 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/23 21:39:26 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_find_axis(t_fdf *ax, char *str)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("No found file\n", 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		j = 0;
		while (j < ft_count_nbr(line))
			j++;
		i++;
		// printf("line : %s\n", line);
		free(line);
	}
	ax->row = i;
	ax->col = j;
	close(fd);
	// printf("done fd\n");
}
