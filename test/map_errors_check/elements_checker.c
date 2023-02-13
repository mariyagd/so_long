/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:32 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 10:39:11 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	walls_checker(char **array, t_list **head, int size_y, int size_x)
{
	int	i;

	i = 0;
	while (array[0][i] != '\0' && array[size_y - 1][i] != '\0')
	{
		if (array[0][i] != '1' || array[size_y - 1][i] != '1')
		{
			free_array(array, size_y);
			ft_lstclear(head, del);
			error_msg_map_one(1);
		}
		i++;
	}
	i = 0;
	while (array[i])
	{
		if (array[i][0] != '1' || array[i][size_x - 1] != '1')
		{
			free_array(array, size_y);
			ft_lstclear(head, del);
			error_msg_map_one(1);
		}
		i++;
	}
}

void	elements_checker(char **array, t_list **head, int size_y)
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
				ft_lstclear(head, del);
				error_msg_map_one(2);
			}
		}
		i++;
	}
}
