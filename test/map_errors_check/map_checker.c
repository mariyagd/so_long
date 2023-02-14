/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:25:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/14 16:15:36 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

/* If all error tests pass, I free the copy_array.
 * I include 'array' and 'copy_array' in all the functions below \
 * so that I can free both in case of an error.*/

void	map_checker(char **array, char **copy_array, t_point size)
{
	walls_checker(array, copy_array, size);
	elements_checker(array, copy_array, size.y);
	nb_player_checker(array, copy_array, size.y);
	nb_exit_checker(array, copy_array, size.y);
	nb_collectible_checker(array, copy_array, size.y);
	accessibility_check(array, copy_array, size);
	free_array(copy_array, size.y);
}
