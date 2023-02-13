/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:23:31 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/13 11:25:34 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

int	find_player_pos_x(char **array)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y] != 0)
	{
		x = 0;
		while (array[y][x] != 0)
		{
			if (array[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	find_player_pos_y(char **array)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y] != 0)
	{
		x = 0;
		while (array[y][x] != 0)
		{
			if (array[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

void	accessibility_check(char **array, t_list **head, int size_y, int size_x)
{	
	int			p_x;
	int			p_y;
	t_point		begin;
	t_point		size;

	p_x = find_player_pos_x(array);
	p_y = find_player_pos_y(array);
	begin.x = p_x;
	begin.y = p_y;
	size.x = size_x;
	size.y = size_y;
	if (p_y < 0 || p_x < 0)
	{
		free_array(array, size_y);
		ft_lstclear(head, del);
		error_msg_map_four(6);
	}
	flood_fill(array, size, begin);
	collectible_accessibility_check(array, head, size_y);
	exit_accessibility_check(array, head, size_y);
}
