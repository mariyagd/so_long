/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:25:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/09 16:25:33 by marvin           ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	map_checker(char **array, t_list **head, int size_x, int size_y)
{
	walls_checker(array, head, size_x, size_y);
	elements_checker(array, head, size_x);
	nb_player_checker(array, head, size_x);
	nb_exit_checker(array, head, size_x);
	nb_collectible_checker(array, head, size_x);
	free_array(array, size_x);
}
