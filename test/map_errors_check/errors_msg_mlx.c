/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msg_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:41:07 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/20 14:32:39 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h" 

/*
 * Je peux inserer error N.4  (i == 4)
	{
		ft_printf("\033[0;31;7mError.0.04:\033[0m");
		ft_printf_fd(2, " Shape error.\n");
	}*/

void	error_msg_mlx(int i, char **map, int size_y)
{
	free_array(map, size_y);
	if (i == 1)
	{
		ft_printf("\033[0;31;7mError.2.00:\033[0m");
		ft_printf_fd(2, " Could not set up the connection to the display\n");
	}
	if (i == 2)
	{
		ft_printf("\033[0;31;7mError.2.01:\033[0m");
		ft_printf_fd(2, " Could not create a window.\n");
	}
	if (i == 3)
	{
		ft_printf("\033[0;31;7mError.2.02:\033[0m");
		ft_printf_fd(2, " Could not create image in memory.\n");
	}
	ft_printf("\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}
