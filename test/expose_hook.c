#include "so_long.h"

void	expose_hook_up(t_data *list)
{
	if (list->map[list->player_pos_y - 1][list->player_pos_x] == 'C')
		list->collect_current += 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	if (list->map[list->player_pos_y - 1][list->player_pos_x] != 'E')
		list->map[list->player_pos_y - 1][list->player_pos_x] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	list->player_pos_y -= 1;
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	if (list->map[list->player_pos_y][list->player_pos_x] == 'E')
	{
		free_array(list->map, list->height);
		exit(0);
	}
}

void	expose_hook_down(t_data *list)
{
	if (list->map[list->player_pos_y + 1][list->player_pos_x] == 'C')
		list->collect_current += 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	if (list->map[list->player_pos_y + 1][list->player_pos_x] != 'E')
		list->map[list->player_pos_y + 1][list->player_pos_x] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	list->player_pos_y += 1;
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	if (list->map[list->player_pos_y][list->player_pos_x] == 'E')
	{
		free_array(list->map, list->height);
		exit(0);
	}
}

void	expose_hook_left(t_data *list)
{
	if (list->map[list->player_pos_y][list->player_pos_x - 1] == 'C')
		list->collect_current += 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	if (list->map[list->player_pos_y][list->player_pos_x - 1] != 'E')
		list->map[list->player_pos_y][list->player_pos_x - 1] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	list->player_pos_x -= 1;
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	if (list->map[list->player_pos_y][list->player_pos_x] == 'E')
	{
		free_array(list->map, list->height);
		exit(0);
	}
}

void	expose_hook_right(t_data *list)
{
	if (list->map[list->player_pos_y][list->player_pos_x + 1] == 'C')
		list->collect_current += 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	if (list->map[list->player_pos_y][list->player_pos_x + 1] != 'E')
		list->map[list->player_pos_y][list->player_pos_x + 1] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	list->player_pos_x += 1;
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	if (list->map[list->player_pos_y][list->player_pos_x] == 'E')
	{
		free_array(list->map, list->height);
		exit(0);
	}
}
