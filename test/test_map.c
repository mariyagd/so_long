/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:24:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/13 17:35:44 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "map_errors_check/errors.h"
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
	int		width;
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

int	main(int ac, char **av)
{
	int		fd;
	t_list	*head;
	t_data	map;

	if (ac != 2)
		error_msg_one(1);
	extension_check(av[1]);
	fd = open(av[1], O_RDONLY);
	open_error_check(fd);
	head = get_line_into_list(fd);
	if (!head)
		error_msg_six(6);
	//map.map_data = prepare_bidimensional_tab(&head);
	
	//TESTS

	map.width = 0;
	map.height = 0;
	
	int	h = 64;
	int	w = 64;


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
	map.width = 6;

	while (map.map_data[map.height])
	{
		map.width = 0;
		while (map.map_data[map.height][map.width])
			map.width++;
		map.height++;
	}
	map.mlx_ptr = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx_ptr, 1920, 1080, "so_long");
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

	mlx_loop(map.mlx_ptr);
	return (0);
}
