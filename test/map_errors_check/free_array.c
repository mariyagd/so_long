/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:51:50 by marvin            #+#    #+#             */
/*   Updated: 2023/02/09 15:52:14 by marvin           ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	free_array(char **array, int size_x)
{
	int	i;

	i = 0;
	while (i <= size_x)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
