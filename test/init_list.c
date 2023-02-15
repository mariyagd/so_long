/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:07:44 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/15 17:08:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_list_image(t_data *list)
{
	int	h;
	int	w;

	list->wall = mlx_xpm_file_to_image(list->mlx_ptr, \
			"sprites/wall.xpm", &w, &h);
	(*list).open_sp = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/open_sp.xpm", &w, &h);
	(*list).collect = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/collect.xpm", &w, &h);
	(*list).player = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/player.xpm", &w, &h);
	(*list).exit = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/exit.xpm", &w, &h);
}

void	init_list_args(t_data *list, char **array)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	(*list).map = array;
	list->height = y;
	list->width = x;
	(*list).player_pos_x = find_player_pos_x(array);
	(*list).player_pos_y = find_player_pos_y(array);
	(*list).collect_max = c;
	init_list_image(list);
}
