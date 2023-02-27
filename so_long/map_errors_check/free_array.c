/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:12:50 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 13:12:52 by mdanchev         ###   lausanne.ch       */
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
