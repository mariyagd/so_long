#include "errors.h"

void	printf_tab2d(char **tab2d)
{
	int	i = 0;
	int	j = 0;

	while (tab2d[i])
	{
		j = 0;
		while (tab2d[i][j])
		{
			ft_printf("%c", tab2d[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

/*ICI JE VEUX ENVOYER PAR COPIE LA TAB2D*/
void	accessibility_checker(char **tab2d, int size_x, int size_y)
{
	(void)size_y;
	(void)size_x;
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 1;
	count = 0;
		while (tab2d[i][j] == '1' || tab2d[i][j] == 'E')
			j++;
		while (tab2d[i][j] != '1' && tab2d[i][j] != 'E')
		{
			if (tab2d[i][j] == 'C' || tab2d[i][j] == 'P')
				count++;
			tab2d[i][j] = '*';
			j++;
		}
		j--;
		i++;
		while (tab2d[i][j] != '1' && tab2d[i][j] != 'E')
			j--;
		printf_tab2d(tab2d);
}

void	map_checker(char **tab2d, int size_x, int size_y)
{
	walls_checker(tab2d, size_x, size_y);
	elements_checker(tab2d);
	nb_player_checker(tab2d);
	nb_exit_checker(tab2d);
	nb_collectible_checker(tab2d);
	accessibility_checker(tab2d, size_x, size_y);
}
