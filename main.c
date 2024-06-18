/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:45:29 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/18 15:43:02 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

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

void	ft_find_axis(t_fdf *ax, char	*str)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(str, O_RDONLY);
	if (fd != 3)
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
		free(line);
	}
	ax->row = i;
	ax->col = j;
	close(fd);
}

void	ft_alloc(t_fdf *nbr)
{
	int	i;

	nbr->plot = malloc(sizeof(t_plot *) * (nbr->col));
	if (!nbr->plot)
		return ;
	i = 0;
	while (i < nbr->col)
	{
		nbr->plot[i] = malloc(sizeof(t_plot) * (nbr->row));
		if (!nbr->plot[i])
			return ;
		i++;
	}
}

void	ft_set_x_y(t_fdf *nbr, char *str)
{
	char	**result;
	char	*line;

	nbr->fd = open(str, O_RDONLY);
	ft_alloc(nbr);
	nbr->i = 0;
	while (nbr->i < nbr->col)
	{
		line = get_next_line(nbr->fd);
		if (!line)
			break ;
		result = ft_split(line, ' ');
		nbr->j = 0;
		while (nbr->j < nbr->row)
		{
			nbr->plot[nbr->i][nbr->j].x = nbr->j;
			nbr->plot[nbr->i][nbr->j].y = nbr->i;
			nbr->plot[nbr->i][nbr->j].z = ft_atoi(result[nbr->j]);
			nbr->j++;
		}
		nbr->i++;
		free(line);
		ft_free(result);
	}
	close (nbr->fd);
}

void	ft_initialize(t_fdf *nbr, char *str)
{
	ft_find_axis(nbr, str);
	ft_set_x_y(nbr, str);
	
}

int	main(int ac, char **av)
{
	t_fdf	number;

	if (ac != 2)
		return (-1);
	check_arg(av);
	ft_initialize(&number, av[1]);
	ft_free_struct(number.plot);
	// printf("col : %d\n", number.col);
	// printf("row : %d\n", number.row);
	// number.i = 0;
	// while (number.i < number.col)
	// {
	// 	number.j = 0;
	// 	while (number.j < number.row)
	// 	{
	// 		printf("(%d, %d) = %d\n", number.i, number.j, (int)number.plot[number.i][number.j].z);
	// 		number.j++;
	// 	}
	// 	number.i++;
	// }
}

	/*สร้างเส้นโครงร่าง แกน x, y*/
	// mlx_t* mlx;
	// mlx_image_t* img; 

	// mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	// if (!mlx)
	// 	exit(EXIT_FAILURE);
	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	// int	x = 0;
	// while (x++ < WIDTH)
	// 	mlx_put_pixel(img, x, 0, get_rgba(255,0,0,255));

	// int y = 0;
	// while (y++ < HEIGHT)
	// 	mlx_put_pixel(img, 0, y, get_rgba(255,0,0,255));

	// mlx_image_to_window(mlx, img, 100, 100);
	// mlx_loop(mlx);
	// mlx_close_window(mlx);
	// mlx_delete_image(mlx, img);
	// mlx_terminate(mlx);

    // return (EXIT_SUCCESS);



	/*อันใหม่*/

	// axis	ax;
	// t_plot	**ptr;
	// int		fd;
	// int		i;
	// t_fdf	s;
	// char	*line;
	// int		x;
	// int		y;
	// int		tmp_x = 0;
	// int		tmp_y = 0;
	// mlx_image_t*	img;
	// mlx_t			*mlx;
	// // float	dx = 0;
	// // float	dy = 0;
	// // mlx_t	*mlx;
	// // mlx_image_t*	img;
	// char	**result;
	// if (ac != 2)
	// 	return (-1);
	// ax = ft_find_axis(av[1]);
	// // printf("col : %d\n", ax.col);
	// // printf("row : %d\n", ax.row);
	// i = 0;
	// ptr = malloc(sizeof(t_plot *) * ax.col);
	// while (i < ax.col)
	// {
	// 	ptr[i] = malloc(sizeof(t_plot) * ax.col);
	// 	i++;
	// }
	// fd = open(av[1], O_RDONLY);
	// mlx = mlx_init(WIDTH, HEIGHT, "TEST", true);
	// if (!mlx)
	// 	exit(EXIT_FAILURE);
	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// y = 0;
	// while (y < ax.row)
	// {
	// 	x = 0;
	// 	result = ft_split(line, ' ');
	// 	while (x < ax.col)
	// 	{
	// 		ptr[x][y].x = x * 10;
	// 		ptr[x][y].y = y * 10;
	// 		ptr[x][y].z = ft_atoi(result[x]);
	// 		tmp_x = ptr[x][y].x;
	// 		tmp_y = ptr[x][y].y;
			
	// 		// ptr[x][y].x = tmp_x + cos(ANGLE_120) * ptr[x][y].z;
	// 		// ptr[x][y].y = tmp_y + sin(ANGLE_120) * ptr[x][y].z;
			
	// 		// ptr[x][y].x = tmp_x * cos(ANGLE_120) + tmp_y * cos(ANGLE_120+2) + ptr[x][y].z * cos(ANGLE_120-2);
	// 		// ptr[x][y].y = tmp_y * sin(ANGLE_120) + tmp_y * sin(ANGLE_120+2) + ptr[x][y].z * sin(ANGLE_120-2);

	// 		// ptr[x][y].x = tmp_x * cos(ANGLE_120) + tmp_y * cos(ANGLE_122) + ptr[x][y].z * cos(ANGLE_118);
	// 		// ptr[x][y].y = tmp_x * sin(ANGLE_120) + tmp_y * sin(ANGLE_122) + ptr[x][y].z * sin(ANGLE_118);
			
	// 		ptr[x][y].x = (tmp_x - tmp_y) * cos(ANGLE);
	// 		ptr[x][y].y = ((tmp_x + tmp_y) * sin(ANGLE) - ptr[x][y].z);
			
	// 		printf("ptr-x : %d\n", ptr[x][y].x);
	// 		printf("ptr-y : %d\n", ptr[x][y].y);
	// 		printf("ptr-z : %d\n",  ptr[x][y].z);
			
	// 		mlx_put_pixel(img, ptr[x][y].x + 100, ptr[x][y].y + 100, get_rgba(255, 255, 255, 255));
	// 		x++;
	// 	}
	// 	y++;
	// 	free(line);
	// 	free(result);
	// }
	// mlx_image_to_window(mlx, img, 0, 0);
	// // mlx_image_to_window(mlx, img, 500, 500);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// close(fd);