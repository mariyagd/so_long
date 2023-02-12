/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:41:07 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 17:41:18 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h" 

/*
 * Je peux inserer error N.4  (i == 4)
	{
		ft_printf("\033[0;31;7mError.0.04:\033[0m");
		ft_printf_fd(2, " Shape error.\n");
	}*/

void	error_msg_one(int i)
{
	if (i == 1)
	{
		ft_printf("\033[0;31;7mError.0.01:\033[0m");
		ft_printf_fd(2, " Please enter only one argument.\n");
	}
	if (i == 2)
	{
		ft_printf("\033[0;31;7mError.0.02:\033[0m");
		ft_printf_fd(2, " Could not open the file.");
		ft_printf_fd(2, " Check the name of your file.\n");
	}
	if (i == 3)
	{
		ft_printf("\033[0;31;7mError.0.03:\033[0m");
		ft_printf_fd(2, " Invalid file. Please enter a .ber file.\n");
	}
	if (i == 4)
	{
		ft_printf("\033[0;31;7mError.0.04:\033[0m");
		ft_printf_fd(2, " Invalid map.\n");
	}
	ft_printf("\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}

void	error_msg_six(int i)
{
	if (i == 6)
	{
		ft_printf("\033[0;31;7mError.0.06:\033[0m");
		ft_printf_fd(2, " Something happened. Could not malloc correctly.\n");
	}
	if (i == 7)
	{
		ft_printf("\033[0;31;7mError.0.07:\033[0m");
		ft_printf_fd(2, " Something happened. Could not malloc correctly.");
		ft_printf_fd(2, " Or the map is empty.\n");
	}
	ft_printf("\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}

void	error_msg_map_one(int i)
{
	if (i == 1)
	{
		ft_printf("\033[0;31;7mError.1.08:\033[0m");
		ft_printf_fd(2, " Map error. Error wall.\n");
	}
	if (i == 2)
	{
		ft_printf("\033[0;31;7mError.1.09:\033[0m");
		ft_printf_fd(2, " Map error. Not an assignable character.\n");
	}
	if (i == 3)
	{
		ft_printf("\033[0;31;7mError.1.10:\033[0m");
		ft_printf_fd(2, " Map error. Number of players is incorrect.\n");
	}
	ft_printf("\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}

void	error_msg_map_four(int i)
{
	if (i == 4)
	{
		ft_printf("\033[0;31;7mError.1.11:\033[0m");
		ft_printf_fd(2, " Map error. Number of exits is incorrect.\n");
	}
	if (i == 5)
	{
		ft_printf("\033[0;31;7mError.1.12:\033[0m");
		ft_printf_fd(2, " Map error. Number of collectibles is incorrect.\n");
	}
	if (i == 6)
	{
		ft_printf("\033[0;31;7mError.1.13:\033[0m");
		ft_printf_fd(2, " Something went wrong.\n");
	}
	ft_printf("\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}


void	error_msg_map_seven(int i)
{
	if (i == 7)
	{
		ft_printf("\033[0;31;7mError.1.14:\033[0m");
		ft_printf_fd(2, " Map error. Collectibles are not accessible.\n");
	}
	if (i == 8)
	{
		ft_printf("\033[0;31;7mError.1.15:\033[0m");
		ft_printf_fd(2, " Map error. Exit is not accessible.\n");
	}
	ft_printf("\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}
