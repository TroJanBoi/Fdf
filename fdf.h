/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:36:27 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/23 22:24:38 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
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
# define WHITE_COLOR 16777215
# define RED_COLOR 16711680

typedef struct s_plot
{
	float			x; // เพิ่มค่าลงได้แล้ว
	float			y; // เพิ่มค่าลงได้แล้ว
	float			z; // เพิ่มค่าลงได้แล้ว
	long			c;
}		t_plot;

typedef struct s_fdf
{
	int			col; // เพิ่มค่าลงได้แล้ว
	int			row; // เพิ่มค่าลงได้แล้ว
	int			fd;
	int			i;
	int			j;
	float		tmp_x;
	float		tmp_y;
	float		dx;
	float		dy;
	float		steps;
	t_plot		**plot;
	mlx_t		*mlx;
	mlx_image_t	*img;
}		t_fdf;

char	*get_next_line(int fd);
void	ft_alloc(t_fdf *nbr);
void	check_arg(char **av);
void	ft_error(char *str, int fd);
long	ft_atoh(char *str);
int		ft_count_nbr(char *nbr);
void	ft_put_pixel(t_fdf *pic, int x, int y, long color);

/*drawline*/
void	ft_drawline(t_fdf *nbr);
void	ft_dda(t_plot start, t_plot end, t_fdf *pic);

/*axis*/
void	ft_find_axis(t_fdf *ax, char *str);

/*color*/
long	set_color(char **color, t_fdf *nbr, int i, int j);
int		get_rgba(int r, int g, int b, int a);
void	ft_find_color(t_fdf *nbr, char *str);

/*free*/
void	ft_free(char **str);
void	ft_free_struct(t_plot **plot);
#endif