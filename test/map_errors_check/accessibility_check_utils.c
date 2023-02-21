/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility_check_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:26:07 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/21 15:39:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	exit_accessibility_check(char **array, char **copy_array, int size_y)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (copy_array[y][x] != 'E')
	{
		x++;
		if (copy_array[y][x] == 0)
		{
			x = 0;
			y++;
		}
	}
	if (copy_array[y + 1][x] == '*' || copy_array[y - 1][x] == '*' || \
			copy_array[y][x + 1] == '*' || copy_array[y][x - 1] == '*')
		return ;
	else
	{
		free_array(array, size_y);
		free_array(copy_array, size_y);
		error_msg_map_seven(8);
	}
}

void	coll_accessibility_check(char **array, char **copy_array,\
		int size_y)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (copy_array[y] != 0)
	{
		x = 0;
		while (copy_array[y][x] != 0)
		{
			if (copy_array[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count != 0)
	{
		free_array(array, size_y);
		free_array(copy_array, size_y);
		error_msg_map_seven(7);
	}
	return ;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (tab[begin.y][begin.x] == 'C' || tab[begin.y][begin.x] == 'P')
		tab[begin.y][begin.x] = '0';
	if (begin.x > size.x - 1 || begin.x < 0 || \
			begin.y > size.y - 1 || begin.y < 0 || \
			tab[begin.y][begin.x] != '0')
		return ;
	tab[begin.y][begin.x] = '*';
	flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}
