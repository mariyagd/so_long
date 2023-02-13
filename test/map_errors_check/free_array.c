/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:51:50 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 10:39:20 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	free_array(char **array, int size_y)
{
	int	i;

	i = 0;
	while (i <= size_y)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
