/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:13:14 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 13:15:43 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

/* If all error tests pass, I free the copy_array.
 * I include 'array' and 'copy_array' in all the functions below
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
