/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:36:27 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/18 01:48:23 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ANGLE 0.523599
# define ANGLE_120 2.09333333333
# define ANGLE_118 2.0597
# define ANGLE_122 2.1263

typedef struct s_plot
{
	float			x; // เพิ่มค่าลงได้แล้ว
	float			y; // เพิ่มค่าลงได้แล้ว
	float			z; // เพิ่มค่าลงได้แล้ว
}		t_plot;

typedef struct s_fdf
{
	int		col; // เพิ่มค่าลงได้แล้ว
	int		row; // เพิ่มค่าลงได้แล้ว
	int		fd;
	int		i;
	int		j;
	t_plot	**plot;
}		t_fdf;

char	*get_next_line(int fd);
int		get_rgba(int r, int g, int b, int a);

void	check_arg(char **av);
void	ft_error(char *str, int fd);

/*free*/
void	ft_free(char **str);
void	ft_free_struct(t_plot **plot);
#endif