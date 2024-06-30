/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:38:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/27 14:31:09 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isallspace(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i++])
	{
		if (str[i] == ' ' || str[i] == '\t')
			count++;
	}
	if (ft_strlen(str) != count)
		return (1);
	return (0);
}

int	ft_isfilefdf(char *str)
{
	char	*file;
	int		size;

	file = ft_strrchr(str, '.');
	if (file)
	{
		size = ft_strlen(file);
		if (!ft_strncmp(file, TYPE_FILE, size))
		{
			return (1);
		}
		return (0);
	}
	return (0);
}

void	check_arg(char **av)
{
	if (ft_isallspace(av[1]) == 0)
		ft_error("No file\n", 2);
	else if (ft_isfilefdf(av[1]) == 0)
		ft_error("No file fdf\n", 2);
}
