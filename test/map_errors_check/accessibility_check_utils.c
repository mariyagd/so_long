/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility_check_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:26:07 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/13 11:26:38 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	exit_accessibility_check(char **array, t_list **head, int size_y)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (array[y][x] != 'E')
	{
		x++;
		if (array[y][x] == 0)
		{
			x = 0;
			y++;
		}
	}
	if (array[y + 1][x] == '*' || array[y - 1][x] == '*' || \
			array[y][x + 1] == '*' || array[y][x + 1] == '*')
		return ;
	else if (!(array[y + 1][x] == '*' || array[y - 1][x] == '*' || \
		array[y][x + 1] == '*' || array[y][x + 1] == '*'))
	{
		free_array(array, size_y);
		ft_lstclear(head, del);
		error_msg_map_seven(8);
	}
}

void	collectible_accessibility_check(char **array, t_list **head, int size_y)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (array[y] != 0)
	{
		x = 0;
		while (array[y][x] != 0)
		{
			if (array[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count != 0)
	{
		free_array(array, size_y);
		ft_lstclear(head, del);
		error_msg_map_seven(7);
	}
	return ;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (tab[begin.y][begin.x] == 'C' || tab[begin.y][begin.x] == 'P')
		tab[begin.y][begin.x] = '0';
	if (begin.x > size.x - 1 || begin.x < 0 || \
			begin.y > size.y - 1 || begin.y < 0 || \
			tab[begin.y][begin.x] != '0')
		return ;
	tab[begin.y][begin.x] = '*';
	flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}
