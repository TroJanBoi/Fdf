/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:45:29 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/23 23:39:11 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

// char **file_reader(int fd)
// {
// 	char *buffer;
// 	char *tmp;
// 	char **ret;
// 	char *t;
	
// 	while (buffer != NULL)
// 	{
// 		tmp = get_next_line(fd);
// 		if (buffer == NULL)
// 			break;
// 		t = buffer;
// 		buffer = ft_strjoin(buffer, tmp);
// 		if (t)
// 			free(t);
// 		if (tmp)
// 			free(tmp);
// 		tmp = NULL;
// 		t = NULL;
// 	}
// 	if (buffer)
// 		ret = ft_split(buffer , '\n');
	
// 	return (ret);
// }

// void find_row_col(char **char_ar)
// {
// 	int row;
// 	int col;

// 	int max_col;
	
// 	while (char_ar[row])
// 	{
// 		col = 0;
// 		while (char_ar[row][col])
// 			col++;
// 		if (max_col < col)
// 			max_col = col;	
// 		row++;
// 	}
// 	nbr->row = row;
// 	nbr->col = max_col;

// }

void	ft_set_x_y(t_fdf *nbr, char *str)
{
	char	**result;
	char	*line;

	nbr->fd = open(str, O_RDONLY);
	if (nbr->fd < 0)
		exit(EXIT_FAILURE);
	ft_alloc(nbr);
	nbr->i = 0;
	printf("start xy\n");
	printf("col : %d\n", nbr->col);
	printf("row : %d\n", nbr->row);
	while (nbr->i < nbr->row)
	{
		line = get_next_line(nbr->fd);
		if (!line)
			break ;
		printf("line : %s\n", line);
		result = ft_split(line, ' ');
		nbr->j = 0;
		while (nbr->j < nbr->col)
		{
			nbr->plot[nbr->i][nbr->j].x = nbr->j * 3;
			nbr->plot[nbr->i][nbr->j].y = nbr->i * 3;
			if (result[nbr->j] != NULL)
				nbr->plot[nbr->i][nbr->j].z = ft_atoi(result[nbr->j]);
			else
				nbr->plot[nbr->i][nbr->j].z = 0;
			// printf("x: %.2f\n", nbr->plot[nbr->i][nbr->j].x);
			// printf("y: %.2f\n", nbr->plot[nbr->i][nbr->j].y);
			// printf("z: %.2f\n", nbr->plot[nbr->i][nbr->j].z);
			// ft_put_pixel(nbr, nbr->i, nbr->j, o[ijpi8uhbn]);klm,lk'nmjkm nokunjk j j';
			// ft_put_pixel(nbr, nbr->plot[nbr->i][nbr->j].x, nbr->plot[nbr->i][nbr->j].y, WHITE_COLOR);
			nbr->j++;
		}
		nbr->i++;
		// printf("xy w\n");
		free(line);
		ft_free(result);
	}
	close (nbr->fd);
	printf("done xy\n");
}

void	ft_initialize(t_fdf *nbr, char *str)
{
	// char **readfile(str(file name))
	// find axis (char **, nbr)
	// set_x_y(char **, nbr)
	// find_color(char **, nbr)
	ft_find_axis(nbr, str);
	ft_set_x_y(nbr, str);
	ft_find_color(nbr, str);
}

void	ft_calculate(t_fdf *n)
{
	n->i = 0;
	while (n->i < n->row)
	{
		n->j = 0;
		while (n->j < n->col)
		{
			n->tmp_x = n->plot[n->i][n->j].x;
			n->tmp_y = n->plot[n->i][n->j].y;
			n->plot[n->i][n->j].x = (n->tmp_x - n->tmp_y) * cos(ANGLE);
			n->plot[n->i][n->j].y = ((n->tmp_x + n->tmp_y) * sin(ANGLE) \
			- n->plot[n->i][n->j].z);
			n->j++;
		}
		n->i++;
	}
}

int	main(int ac, char **av)
{
	t_fdf	number;

	if (ac != 2)
		return (-1);
	check_arg(av);
	ft_initialize(&number, av[1]);
	printf("row : %d\n", number.row);
	printf("col : %d\n", number.col);
	number.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!number.mlx)
		exit(EXIT_FAILURE);
	number.img = mlx_new_image(number.mlx, WIDTH, HEIGHT);
	// for (int h = 1; h < number.img->height; h++)
	// 	for (int w = 1; w < number.img->width; w++)
	// 		mlx_put_pixel(number.img, w, h, 255);
	ft_calculate(&number);
	printf("calculate\n");
	ft_drawline(&number);
	printf("drawline\n");
	mlx_image_to_window(number.mlx, number.img, 0, 0);
	mlx_loop(number.mlx);
	mlx_terminate(number.mlx);
	ft_free_struct(number.plot);
}
