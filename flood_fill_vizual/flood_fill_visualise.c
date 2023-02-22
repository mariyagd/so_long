/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_visualise.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:25:29 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 14:14:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef	struct s_point
{
	int	x;
	int	y;
}		t_point;


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
			if (i == begin.y && j == begin.x)
			{
				printf("\033[0;31;7m");
				printf("%c", tab[begin.y][begin.x]);
				printf("\033[0m");
			}

			else
				printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n\n");
	if (tab[begin.y][begin.x] == 'C' || \
			tab[begin.y][begin.x] == 'P')
		tab[begin.y][begin.x] = '0';

	if (begin.x > size.x - 1 || begin.x < 0 || \
			begin.y > size.y - 1 || begin.y < 0 || \
			tab[begin.y][begin.x] != '0')
			return ;
	tab[begin.y][begin.x] = '*';
	getchar();	
		i = 0;
	 j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i == begin.y && j == begin.x)
			{
				printf("\033[0;32;7m");
				printf("%c", tab[begin.y][begin.x]);
				printf("\033[0m");
			}

			else
				printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
		printf("\n\nfill(tab, size, (t_point){begin.x - 1, begin.y}\n");
	fill(tab, size, (t_point){begin.x - 1, begin.y});
	

	getchar();	
		i = 0;
	 j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i == begin.y && j == begin.x)
			{
				printf("\033[0;32;7m");
				printf("%c", tab[begin.y][begin.x]);
				printf("\033[0m");
			}

			else
				printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
		printf("\n\nfill(tab, size, (t_point){begin.x + 1, begin.y})\n");
	fill(tab, size, (t_point){begin.x + 1, begin.y});
	

	getchar();	
		i = 0;
	 j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i == begin.y && j == begin.x)
			{
				printf("\033[0;32;7m");
				printf("%c", tab[begin.y][begin.x]);
				printf("\033[0m");
			}

			else
				printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
		printf("\n\nfill(tab, size, (t_point){begin.x, begin.y - 1}\n");
	fill(tab, size, (t_point){begin.x, begin.y - 1});
	

	getchar();	
		i = 0;
	 j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (i == begin.y && j == begin.x)
			{
				printf("\033[0;32;7m");
				printf("%c", tab[begin.y][begin.x]);
				printf("\033[0m");
			}

			else
				printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\nfill(tab, size, (t_point){begin.x, begin.y + 1}\n");
	fill(tab, size, (t_point){begin.x, begin.y + 1});

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	
	fill(tab, size, begin);
}

/*
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
*/


#include <stdlib.h>
#include <string.h>
int	main(void)
{
	t_point	size;
	t_point	begin; 

	//width of map
	size.x = 8;
	//height of map
	size.y = 5;

	//player position in x axes
	begin.x = 4;
	//player pos in y axes
	begin.y = 3;

	char map[5][8] = { 
					"1111111\0",
					"10C0001\0",
					"10000P1\0",
					"1C0E001\0",
					"1111111\0"
					};

	char **maps;
	maps = NULL;

	maps = calloc((size.y + 1) , sizeof(char *));
	if (!maps)
		return (1);
	int	i = 0;
	while (i < size.y)
	{
		maps[i] = strdup(map[i]);
		i++;
	}
	flood_fill(maps, size, begin);
	return (0);
}
