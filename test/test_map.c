/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:24:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/15 17:21:34 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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
	list.mlx_win = mlx_new_window(list.mlx_ptr, list.width * SPRITE , \
			list.height * SPRITE, "so_long");
	image_window(&list, array);
	mlx_loop(list.mlx_ptr);
	return (0);
}
