#include "mlx/mlx.h"

typedef struct	s_data 
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_ground;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	int		height;
	int		wight;
	int		player_pos_x;
	int		player_pos_y;
	int		score_max;
	int		score_current;
	char	**map_data;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*player;
}			t_data;

#include <stdlib.h>
int	main(void)
{
	t_data	map;
	int	w = 64;
	int	h = 64;

	map.map_data = malloc(5 * sizeof(char *));
	int	x = 0;
	int	y = 0;
	while (y < 4)
	{
		map.map_data[y] = malloc(6 * sizeof(char));
		y++;
	}
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			map.map_data[y][x++] = '0';
			if (x < 5)
			{
				map.map_data[y][x] = '1';
				x++;
			}
		}
		map.map_data[y][x] = '0';
		y++;
	}

	map.height = 5;
	map.wight = 6;
	
	map.mlx_ptr = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx_ptr, 1920, 1080, "so_long");
//	img.img = mlx_new_image(mlx, 64, 64);
	map.img_wall = mlx_xpm_file_to_image(map.mlx_ptr, "sprites/wall.xpm", &w, &h);
	map.img_ground = mlx_xpm_file_to_image(map.mlx_ptr, "sprites/grass.xpm", &w, &h);
	map.img_coin = mlx_xpm_file_to_image(map.mlx_ptr, "sprites/wood_stick.xpm", &w, &h);
	map.img_player = mlx_xpm_file_to_image(map.mlx_ptr, "sprites/owl.xpm", &w, &h);
	map.img_exit = mlx_xpm_file_to_image(map.mlx_ptr, "sprites/exit_full.xpm", &w, &h);
	int	i = 0;
	int j = 0;
	while (map.map_data[i])
	{
		j = 0;
		while (map.map_data[i][j])
		{
			if (map.map_data[i][j] == '1')
				mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_wall, j * 64, i * 64);
			else if (map.map_data[i][j] == '0')
				mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_ground, j * 64, i * 64);
			else if (map.map_data[i][j] == 'P')
				mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_player, j * 64, i * 64);
			else if (map.map_data[i][j] == 'E')
				mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_exit, j * 64, i * 64);
			else if (map.map_data[i][j] == 'C')
				mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_coin, j * 64, i * 64);
			j++;
		}
		i++;
	}
//	mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_wall, 10 * 64, 10 * 64);
//	mlx_put_image_to_window(map.mlx_ptr, map.mlx_win, map.img_wall, 11 * 64, 10 * 64);
	mlx_loop(map.mlx_ptr);
}
