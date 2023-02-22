/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:50:24 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 12:50:26 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_list	*head;
	t_data	list;

	if (ac != 2)
		error_msg_one(1);
	extension_check(av[1]);
	fd = open(av[1], O_RDONLY);
	open_error_check(fd);
	head = get_line_into_list(fd);
	if (!head)
		error_msg_six(6);
	list.map = prepare_bidimensional_tab(&head);
	list.mlx_ptr = mlx_init();
	if (list.mlx_ptr == NULL)
		error_msg_mlx(1, list.map, list.height);
	init_list_args(&list);
	list.mlx_win = mlx_new_window(list.mlx_ptr, list.width * SPRITE, \
			list.height * SPRITE, "so_long");
	if (list.mlx_win == NULL)
		error_msg_mlx(2, list.map, list.height);
	image_window(&list);
	events(&list);
	mlx_loop(list.mlx_ptr);
	return (0);
}
