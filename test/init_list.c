/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:07:44 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/20 15:00:16 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_list_image(t_data *list)
{
	int	h;
	int	w;

	list->wall = mlx_xpm_file_to_image(list->mlx_ptr, \
			"sprites/wall.xpm", &w, &h);
	if (list->wall == NULL)
		error_msg_mlx(3, list->map, list->height);
	(*list).open_sp = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/open_sp.xpm", &w, &h);
	if (list->open_sp == NULL)
		error_msg_mlx(3, list->map, list->height);
	(*list).collect = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/collect.xpm", &w, &h);
	if (list->collect == NULL)
		error_msg_mlx(3, list->map, list->height);
	(*list).player = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/player.xpm", &w, &h);
	if (list->player == NULL)
		error_msg_mlx(3, list->map, list->height);
	(*list).exit = mlx_xpm_file_to_image((*list).mlx_ptr, \
			"sprites/exit.xpm", &w, &h);
	if (list->exit == NULL)
		error_msg_mlx(3, list->map, list->height);
}

void	init_list_args(t_data *list)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (list->map[y])
	{
		x = 0;
		while (list->map[y][x])
		{
			if (list->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	list->height = y;
	list->width = x;
	(*list).player_pos_x = find_player_pos_x(list->map);
	(*list).player_pos_y = find_player_pos_y(list->map);
	ft_printf("MAX = %d\n", c);
	(*list).collect_max = c;
	(*list).collect_current = 0;
	list->flag_collect = 0;
	init_list_image(list);
}
