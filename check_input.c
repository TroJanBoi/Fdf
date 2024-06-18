/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:38:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/06/17 05:01:54 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isallspace(char *str)
{
	int	i;
	int	count;

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

void	check_arg(char **av)
{
	if (ft_isallspace(av[1]) == 0)
		ft_error("No file\n", 0);
}