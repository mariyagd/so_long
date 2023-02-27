/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:51:42 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 14:15:17 by mdanchev         ###   lausanne.ch       */
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

void	accessibility_check(char **array, char **copy_array, t_point size)
{	
	int			p_x;
	int			p_y;
	t_point		begin;

	p_x = find_player_pos_x(array);
	p_y = find_player_pos_y(array);
	begin.x = p_x;
	begin.y = p_y;
	if (p_y < 0 || p_x < 0)
	{
		free_array(array, size.y);
		free_array(copy_array, size.y);
		error_msg_map_four(6);
	}
	flood_fill(copy_array, size, begin);
	coll_accessibility_check(array, copy_array, size.y);
	exit_accessibility_check(array, copy_array, size.y);
}
