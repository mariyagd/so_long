/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:24:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/14 18:41:14 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "map_errors_check/errors.h"
#include "mlx/mlx.h"
#include "so_long.h"

typedef struct	s_data 
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*wall;
	void	*open_sp;
	void	*collect;
	void	*player;
	void	*exit;
	char	**map;
	int		height;
	int		width;
	int		player_pos_x;
	int		player_pos_y;
	int		collect_max;
	int		collect_current;
	int		w;
	int		h;
}			t_data;

void	init_list_image(t_data *list)
{
	list->wall = mlx_xpm_file_to_image(list->mlx_ptr, "sprites/wall.xpm", &list->width, &list->height);
	(*list).open_sp = mlx_xpm_file_to_image((*list).mlx_ptr, "sprites/grass.xpm", &list->w, &list->h);
	(*list).collect = mlx_xpm_file_to_image((*list).mlx_ptr, "sprites/wood_stick.xpm", &list->w, &list->h);
	(*list).player = mlx_xpm_file_to_image((*list).mlx_ptr, "sprites/owl.xpm", &list->w, &list->h);
	(*list).exit = mlx_xpm_file_to_image((*list).mlx_ptr, "sprites/exit_full.xpm", &list->w, &list->h);
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
	(*list).height = y;
	(*list).width = x;
	(*list).player_pos_x = find_player_pos_x(array);
	(*list).player_pos_y = find_player_pos_y(array);
	(*list).collect_max = c;
	init_list_image(list);
}

void	image_window2(t_data *list, char **array)
{
	int	i;
	int j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, j * SPRITE, i * SPRITE);
			j++;
		}
		i++;
	}
}
void	image_window(t_data *list, char **array)
{
	int	i;
	int j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, j * SPRITE, i * SPRITE);
			if (array[i][j] == '1')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->wall, j * SPRITE, i * SPRITE);
			else if (array[i][j] == '0')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->open_sp, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'C')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->collect, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'P')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->player, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'E')
				mlx_put_image_to_window(list->mlx_ptr, list->mlx_win, list->exit, j * SPRITE, i * SPRITE);
			j++;
		}
		i++;
	}
}


int	main(int ac, char **av)
{
	int		fd;
	t_list	*head;
	t_data	list;
	char	**array;

	if (ac != 2)
		error_msg_one(1);
	extension_check(av[1]);
	fd = open(av[1], O_RDONLY);
	open_error_check(fd);
	head = get_line_into_list(fd);
	if (!head)
		error_msg_six(6);
	array = prepare_bidimensional_tab(&head);
	list.mlx_ptr = mlx_init();
	init_list_args(&list, array);	
	list.mlx_win = mlx_new_window(list.mlx_ptr, list.width * SPRITE , list.height * SPRITE, "so_long");
	image_window(&list, array);
	mlx_loop(list.mlx_ptr);
	/*
	int		x = 0;
	int		y = 0;

	while (array[y] != NULL)
	{
		x = 0;
		while (array[y][x] != '\0')
		{
			ft_printf("%c", array[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}*/
	/*
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
	img_wall = mlx_xpm_file_to_image(mlx_ptr, "sprites/wall.xpm", &w, &h);
	img_ground = mlx_xpm_file_to_image(mlx_ptr, "sprites/grass.xpm", &w, &h);
	img_coin = mlx_xpm_file_to_image(mlx_ptr, "sprites/wood_stick.xpm", &w, &h);
	img_player = mlx_xpm_file_to_image(mlx_ptr, "sprites/owl.xpm", &w, &h);
	img_exit = mlx_xpm_file_to_image(mlx_ptr, "sprites/exit_full.xpm", &w, &h);

	int	i = 0;
	int j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_wall, j * SPRITE, i * SPRITE);
			else if (array[i][j] == '0')
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_ground, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'P')
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_player, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'E')
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_exit, j * SPRITE, i * SPRITE);
			else if (array[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, mlx_win, img_coin, j * SPRITE, i * SPRITE);
			j++;
		}
		i++;
	}

	mlx_loop(mlx_ptr);*/
	return (0);
}
