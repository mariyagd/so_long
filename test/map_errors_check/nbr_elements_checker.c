/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_elements_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:25:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/14 15:32:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	nb_player_checker(char **array, char **copy_array, int size_y)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		free_array(array, size_y);
		free_array(copy_array, size_y);
		error_msg_map_one(3);
	}
}

void	nb_exit_checker(char **array, char **copy_array, int size_y)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		free_array(array, size_y);
		free_array(copy_array, size_y);
		error_msg_map_four(4);
	}
}

void	nb_collectible_checker(char **array, char **copy_array, int size_y)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
	{
		free_array(array, size_y);
		free_array(copy_array, size_y);
		error_msg_map_four(5);
	}
}
