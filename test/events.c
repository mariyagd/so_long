#include "so_long.h"

int	close_program(t_data *list)
{
		ft_printf("EXIT\n");
		free_array(list->map, list->height);
		exit(0);
}

void	prepare_to_exit(int keycode, t_data *list)
{
	if ((keycode == ARR_UP || keycode == W) && \
			list->map[list->player_pos_y - 1][list->player_pos_x] != '1') 
		expose_hook_up(list, keycode);
	if ((keycode == ARR_DWN || keycode == S) && \
			list->map[list->player_pos_y + 1][list->player_pos_x] != '1')
		expose_hook_down(list, keycode);
	if ((keycode == ARR_L || keycode == A) && \
			list->map[list->player_pos_y][list->player_pos_x - 1] != '1')
		expose_hook_left(list, keycode);
	if ((keycode == ARR_R || keycode == D) && \
			list->map[list->player_pos_y][list->player_pos_x + 1] != '1')
		expose_hook_right(list, keycode);
}

void	key_hook(int keycode, t_data *list)
{
	if (list->flag_collect == 1)
		prepare_to_exit(keycode, list);
	else if ((keycode == ARR_UP || keycode == W) && \
			list->map[list->player_pos_y - 1][list->player_pos_x] != '1' && \
			(list->map[list->player_pos_y - 1][list->player_pos_x] != 'E' && list->flag_exit != 1 && list->flag_collect != 1))
		expose_hook_up(list, keycode);
	else if ((keycode == ARR_DWN || keycode == S) && \
			list->map[list->player_pos_y + 1][list->player_pos_x] != '1' && \
			list->map[list->player_pos_y + 1][list->player_pos_x] != 'E')
		expose_hook_down(list, keycode);
	else if ((keycode == ARR_L || keycode == A) && \
			list->map[list->player_pos_y][list->player_pos_x - 1] != '1' && \
			list->map[list->player_pos_y][list->player_pos_x - 1] != 'E')
		expose_hook_left(list, keycode);
	else if ((keycode == ARR_R || keycode == D) && \
			list->map[list->player_pos_y][list->player_pos_x + 1] != '1' && \
			list->map[list->player_pos_y][list->player_pos_x + 1] != 'E')
		expose_hook_right(list, keycode);
	else if (keycode == ESC)
		close_program(list);
}

int	funct_ptr(int key, t_data *list)
{
	key_hook(key, list);
	return (0);
}


void	events(t_data *list)
{
	mlx_key_hook(list->mlx_win, funct_ptr, list);
	mlx_hook(list->mlx_win, 17, 0, close_program, list);
}
