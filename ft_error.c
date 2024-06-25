/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 04:07:52 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/25 21:53:58 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(EXIT_FAILURE);
}

void	ft_error_sq(char *str, int fd, t_fdf *nbr)
{
	ft_free(nbr->map);
	ft_putstr_fd(str, fd);
	exit(EXIT_FAILURE);
}

void	ft_check_fd(char *str, int fd, t_fdf *nbr)
{
	char	*all;

	all = ft_strjoin("No file ", str);
	if (nbr->fd == -1)
	{
		ft_putstr_fd(all, fd);
		write(fd, "\n", 1);
		close (nbr->fd);
		free(all);
		exit(EXIT_FAILURE);
	}
	free(all);
}
