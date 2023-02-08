#include "errors.h"

void	walls_checker(char **tab2d, int size_x, int size_y)
{
	int	i;

	i = 0;
	while (tab2d[0][i] != '\0' && tab2d[size_x - 1][i] != '\0')
	{
		if (tab2d[0][i] != '1'|| tab2d[size_x - 1][i] != '1')
		{
			free_tab(tab2d); //FREE AVANT ERROR?
			error_msg_map(1);
		}
		i++;
	}
	i = 0;
	while (tab2d[i])
	{
		if (tab2d[i][0] != '1' || tab2d[i][size_y - 1] != '1')
		{
			free_tab(tab2d); // FREE AVANT ERROR
			error_msg_map(1);
		}
		i++;
	}
}

void	elements_checker(char **tab2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (tab2d[i] != 0) 
	{
		j = 0;
		while (tab2d[i][j] != 0)
		{
			if (tab2d[i][j] == 'P' || tab2d[i][j] == '1' || \
					tab2d[i][j] == '0' || tab2d[i][j] == 'C' || \
					tab2d[i][j] =='E')
			{
				j++;
			}
			else
			{
				free_tab(tab2d); //FREE AVANT ERROR?
				error_msg_map(2);
			}
		}
		i++;
	}
}
