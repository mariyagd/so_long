/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:24:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/03 15:36:21 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	error_msg(int i);

int	main(int ac, char **av)
{
	int		fd;
	
	if (ac != 2)
		error_msg(1);
	extension_check(av[1]);
	fd = open(av[1], O_RDONLY);
	open_error_check(fd);
	prepare_bidimensional_tab(fd, &av[1]);
	return (0);
}

