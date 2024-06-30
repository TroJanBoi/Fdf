/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:45:29 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/27 14:38:36 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	ft_set_x_y(t_fdf *nbr)
{
	char	**result;

	ft_alloc(nbr);
	nbr->i = 0;
	while (nbr->i < nbr->row)
	{
		result = ft_split(nbr->map[nbr->i], ' ');
		nbr->j = 0;
		while (nbr->j < nbr->col)
		{
			nbr->plot[nbr->i][nbr->j].x = 0;
			nbr->plot[nbr->i][nbr->j].y = 0;
			nbr->plot[nbr->i][nbr->j].x = (float)nbr->j * nbr->radio * 0.5;
			nbr->plot[nbr->i][nbr->j].y = (float)nbr->i * nbr->radio * 0.5;
			if (result[nbr->j] != NULL)
				nbr->plot[nbr->i][nbr->j].z = (float)ft_atoi(result[nbr->j]);
			else
				nbr->plot[nbr->i][nbr->j].z = 0;
			nbr->j++;
		}
		nbr->i++;
		ft_free(result);
	}
}

void	ft_initialize(t_fdf *nbr, char *str)
{
	file_reader(nbr, str);
	ft_find_axis(nbr);
	ft_find_radio(nbr);
	ft_set_x_y(nbr);
	ft_find_color(nbr);
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
			n->plot[n->i][n->j].x = (n->tmp_x - n->tmp_y) * 0.866;
			n->plot[n->i][n->j].y = ((n->tmp_x + n->tmp_y) * 0.5 \
			- n->plot[n->i][n->j].z);
			n->j++;
		}
		n->i++;
	}
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_close(param);
}

int	main(int ac, char **av)
{
	t_fdf	number;

	if (ac != 2)
		ft_error("No file\n", 2);
	check_arg(av);
	ft_initialize(&number, av[1]);
	number.mlx = mlx_init(WIDTH, HEIGHT, "FdF ", false);
	if (!number.mlx)
		exit(EXIT_FAILURE);
	number.img = mlx_new_image(number.mlx, WIDTH, HEIGHT);
	ft_calculate(&number);
	ft_drawline(&number);
	mlx_image_to_window(number.mlx, number.img, 0, 0);
	mlx_key_hook(number.mlx, &ft_keyhook, &number);
	mlx_loop(number.mlx);
	ft_close(&number);
}
