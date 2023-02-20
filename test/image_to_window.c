/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:07:02 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/20 09:54:18 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_image_to_window(t_data *list,int i, int	j)
{
	while (list->map[++i] != NULL)
	{
		j = 0;
		while (list->map[i][j] != '\0')
		{
			mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
					list->open_sp, j * SPRITE, i * SPRITE);
			if (list->map[i][j] == '1')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->wall, j * SPRITE, i * SPRITE);
			else if (list->map[i][j] == '0')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->open_sp, j * SPRITE, i * SPRITE);
			else if (list->map[i][j] == 'C')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->collect, j * SPRITE, i * SPRITE);
			else if (list->map[i][j] == 'P')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->player, j * SPRITE, i * SPRITE);
			else if (list->map[i][j] == 'E')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->exit, j * SPRITE, i * SPRITE);
			j++;
		}
	}
}

void	image_window(t_data *list)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	put_image_to_window(list, i, j);
}
