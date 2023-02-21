#include "so_long.h"

void	expose_hook_up(t_data *list, int keycode)
{
	if (list->map[list->player_pos_y - 1][list->player_pos_x] == 'C')
		list->collect_current += 1;
	else if (list->map[list->player_pos_y - 1][list->player_pos_x] == 'E' && \
			list->flag_collect == 1)
		list->flag_exit = 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	list->map[list->player_pos_y - 1][list->player_pos_x] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			list->player_pos_x * SPRITE, (list->player_pos_y - 1) * SPRITE);
	list->mvt_count += 1;
	print_key(keycode, list->mvt_count);
	if (list->flag_exit == 1)
		close_program(list);
	list->player_pos_y -= 1;
}

void	expose_hook_down(t_data *list, int keycode)
{
	if (list->map[list->player_pos_y + 1][list->player_pos_x] == 'C')
		list->collect_current += 1;
	else if (list->map[list->player_pos_y + 1][list->player_pos_x] == 'E' && \
			list->flag_collect == 1)
		list->flag_exit = 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	list->map[list->player_pos_y + 1][list->player_pos_x] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			list->player_pos_x * SPRITE, (list->player_pos_y + 1)* SPRITE);
	list->mvt_count += 1;
	print_key(keycode, list->mvt_count);
	if (list->flag_exit == 1)
		close_program(list);
	list->player_pos_y += 1;
}

void	expose_hook_left(t_data *list, int keycode)
{
	if (list->map[list->player_pos_y][list->player_pos_x - 1] == 'C')
		list->collect_current += 1;
	else if (list->map[list->player_pos_y][list->player_pos_x - 1] == 'E' && \
			list->flag_collect == 1)
		list->flag_exit = 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	list->map[list->player_pos_y][list->player_pos_x - 1] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			(list->player_pos_x - 1) * SPRITE, list->player_pos_y * SPRITE);
	list->mvt_count += 1;
	print_key(keycode, list->mvt_count);
	if (list->flag_exit == 1)
		close_program(list);
	list->player_pos_x -= 1;
}

void	expose_hook_right(t_data *list, int keycode)
{
	if (list->map[list->player_pos_y][list->player_pos_x + 1] == 'C')
		list->collect_current += 1;
	else if (list->map[list->player_pos_y][list->player_pos_x + 1] == 'E' && \
			list->flag_collect == 1)
		list->flag_exit = 1;
	if (list->collect_current == list->collect_max)
		list->flag_collect = 1;
	list->map[list->player_pos_y][list->player_pos_x] = '0';
	list->map[list->player_pos_y][list->player_pos_x + 1] = 'P';
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, \
			list->player_pos_x * SPRITE, list->player_pos_y * SPRITE);
	mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, \
			(list->player_pos_x + 1) * SPRITE, list->player_pos_y * SPRITE);
	list->mvt_count += 1;
	print_key(keycode, list->mvt_count);
	if (list->flag_exit == 1)
		close_program(list);
	list->player_pos_x += 1;
}
