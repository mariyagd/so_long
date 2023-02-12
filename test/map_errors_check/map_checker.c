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
#include <stdio.h>

typedef	struct s_point
{
	int	x;
	int	y;
}		t_point;

int	find_player_pos_x(char **array)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y] != 0)
	{
		x = 0;
		while (array[y][x] != 0)
		{
			if (array[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}


int	find_player_pos_y(char **array)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (array[y] != 0)
	{
		x = 0;
		while (array[y][x] != 0)
		{
			if (array[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

#include <stdio.h>
void	fill(char **tab, t_point size, t_point begin)
{
	getchar();	
	int	i = 0;
	int j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_printf("%c", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
		ft_printf("\n\n\n");
	if (tab[begin.y][begin.x] == 'C' || \
			tab[begin.y][begin.x] == 'P')
		tab[begin.y][begin.x] = '0';

	if (begin.x > size.x - 1 || begin.x < 0 || \
			begin.y > size.y - 1 || begin.y < 0 || \
			tab[begin.y][begin.x] != '0')
			return ;
	tab[begin.y][begin.x] = '*';
	fill(tab, size, (t_point){begin.x - 1, begin.y});
	fill(tab, size, (t_point){begin.x + 1, begin.y});
	fill(tab, size, (t_point){begin.x, begin.y - 1});
	fill(tab, size, (t_point){begin.x, begin.y + 1});

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	
	fill(tab, size, begin);
}

void	exit_accessibility_check(char **array, t_list **head, int size_x)
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
		return;
	else if (!(array[y + 1][x] == '*' || array[y - 1][x] == '*' || \
		array[y][x + 1] == '*' || array[y][x + 1] == '*'))
	{
		free_array(array, size_x);
		ft_lstclear(head, del);
		error_msg_map_seven(8);
	}
}

void	collectible_accessibility_check(char **array, t_list **head, int size_x)
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
		free_array(array, size_x);
		ft_lstclear(head, del);
		error_msg_map_seven(7);
	}
	else
		return ;
}

void	accessibility_check(char **array, t_list **head, int size_x, int size_y)
{	
	int	p_x;
	int	p_y;

	(void)size_x;
	(void)size_y;
	p_x = find_player_pos_x(array);
	p_y = find_player_pos_y(array);
	if (p_y < 0 || p_x < 0)
	{
		free_array(array, size_x);
		ft_lstclear(head, del);
		error_msg_map_four(6);
	}
	t_point	begin;
	begin.x = p_x;
	begin.y = p_y;

	t_point size;
	size.x = size_y;
	size.y = size_x;

	flood_fill(array, size, begin);
	printf("size max x = %d\n", size_x);
	printf("size max y = %d\n", size_y);
	printf("position player x = %d\n", p_x);
	printf("position player y = %d\n", p_y);
	int	i = 0;
	int j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}

	collectible_accessibility_check(array, head, size_x);
	exit_accessibility_check(array, head, size_x);
}

void	map_checker(char **array, t_list **head, int size_x, int size_y)
{
	walls_checker(array, head, size_x, size_y);
	elements_checker(array, head, size_x);
	nb_player_checker(array, head, size_x);
	nb_exit_checker(array, head, size_x);
	nb_collectible_checker(array, head, size_x);
	accessibility_check(array, head, size_x, size_y);
	free_array(array, size_x);
}
