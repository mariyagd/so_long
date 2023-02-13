/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:25:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 11:26:42 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	map_checker(char **array, t_list **head, int size_y, int size_x)
{
	walls_checker(array, head, size_y, size_x);
	elements_checker(array, head, size_y);
	nb_player_checker(array, head, size_y);
	nb_exit_checker(array, head, size_y);
	nb_collectible_checker(array, head, size_y);
	accessibility_check(array, head, size_y, size_x);
	free_array(array, size_y);
}
