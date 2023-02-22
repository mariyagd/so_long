/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:10:44 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 13:10:47 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	walls_checker(char **array, char **copy_array, t_point size)
{
	int	i;

	i = 0;
	while (array[0][i] != '\0' && array[size.y - 1][i] != '\0')
	{
		if (array[0][i] != '1' || array[size.y - 1][i] != '1')
		{
			free_array(array, size.y);
			free_array(copy_array, size.y);
			error_msg_map_one(1);
		}
		i++;
	}
	i = 0;
	while (array[i])
	{
		if (array[i][0] != '1' || array[i][size.x - 1] != '1')
		{
			free_array(array, size.y);
			free_array(copy_array, size.y);
			error_msg_map_one(1);
		}
		i++;
	}
}

void	elements_checker(char **array, char **copy_array, int size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i] != 0)
	{
		j = 0;
		while (array[i][j] != 0)
		{
			if (array[i][j] == 'P' || array[i][j] == '1' || \
					array[i][j] == '0' || array[i][j] == 'C' || \
					array[i][j] == 'E')
			{
				j++;
			}
			else
			{
				free_array(array, size_y);
				free_array(copy_array, size_y);
				error_msg_map_one(2);
			}
		}
		i++;
	}
}
