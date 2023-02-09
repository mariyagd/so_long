/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:24:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 16:27:00 by marvin           ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "map_errors_check/errors.h"

int	main(int ac, char **av)
{
	int		fd;
	t_list	*head;

	if (ac != 2)
		error_msg_one(1);
	extension_check(av[1]);
	fd = open(av[1], O_RDONLY);
	open_error_check(fd);
	head = get_line_into_list(fd);
	if (!head)
		error_msg_six(6);
	prepare_bidimensional_tab(&head);
	return (0);
}
