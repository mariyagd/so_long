/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:01:16 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/27 12:03:00 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	max = 0;
	if (len > 0)
	{
		max = tab[i];
		i++;
	}
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[6] = {-2, -9, -10, -6, -8, -3};
	printf("%d\n", max(tab, 6));
	return (0);
}
*/
