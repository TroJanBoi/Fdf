/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:47:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/25 21:30:29 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_reader(t_fdf *nbr, char *str)
{
	char	*buffer;
	char	*tmp;
	char	*t;

	nbr->fd = open(str, O_RDONLY);
	ft_check_fd(str, 2, nbr);
	buffer = ft_strdup(" ");
	while (buffer != NULL)
	{
		tmp = get_next_line(nbr->fd);
		if (tmp == NULL)
			break ;
		t = buffer;
		buffer = ft_strjoin(buffer, tmp);
		if (t)
			free(t);
		if (tmp)
			free(tmp);
		tmp = NULL;
		t = NULL;
	}
	if (buffer)
		nbr->map = ft_split(buffer, '\n');
	free(buffer);
	close (nbr->fd);
}
