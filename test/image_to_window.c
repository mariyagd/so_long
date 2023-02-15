/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:07:02 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/15 17:07:37 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_image_to_window(t_data *list, char **array, int	i, int	j)
{
	while (array[++i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
					list->open_sp, j * SPRITE, i * SPRITE);
			if (array[i][j] == '1')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->wall, j * SPRITE, i * SPRITE);
			else if (array[i][j] == '0')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->open_sp, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'C')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->collect, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'P')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->player, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'E')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, \
						list->exit, j * SPRITE, i * SPRITE);
			j++;
		}
	}
}

void	image_window(t_data *list, char **array)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	put_image_to_window(list, array, i, j);
}
