/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:45:29 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/11 19:31:13 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	main(int ac, char **av)
{
	// int fd;
	// char *line;
	// int count;
	// if (ac < 1)
	// 	return (-1);
	// printf("file : %s\n", av[1]);
	// count = 0;
	// fd = open(av[1], O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	count++;
	// 	printf("%zu\n", ft_strlen(line));
	// 	free(line);
	// }
	// printf("y : %d\n", count);
	// close(fd);
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