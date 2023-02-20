/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:24:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/20 15:19:13 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

# define 	ARR_UP	126
# define	W		13
# define	ARR_DWN	125
# define	S		1
# define	ARR_L	123
# define 	A		0
# define 	ARR_R	124
# define	D		2

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
	list.mlx_win = mlx_new_window(list.mlx_ptr, list.width * SPRITE , \
			list.height * SPRITE, "so_long");
	if (list.mlx_win == NULL)
		error_msg_mlx(2, list.map, list.height);
	image_window(&list);
	events(&list);
	mlx_loop(list.mlx_ptr);
	return (0);
}
