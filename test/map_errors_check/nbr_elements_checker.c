/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_elements_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:25:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/09 16:26:04 by marvin           ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	nb_player_checker(char **array, t_list **head, int size_x)
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
		free_array(array, size_x);
		ft_lstclear(head, del);
		error_msg_map_one(3);
	}
}

void	nb_exit_checker(char **array, t_list **head, int size_x)
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
		free_array(array, size_x);
		ft_lstclear(head, del);
		error_msg_map_four(4);
	}
}

void	nb_collectible_checker(char **array, t_list **head, int size_x)
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
		free_array(array, size_x);
		ft_lstclear(head, del);
		error_msg_map_four(5);
	}
}
