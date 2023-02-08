#include "errors.h"

/*Can't examine target process's malloc zone asan_0x105304950, so memory analysis will be incomplete or incorrect.
Reason: for security, cannot load non-system library /Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/lib/darwin/libclang_rt.asan_osx_dynamic.dylib*/

/*COMMENT FREE UN TABLEAU 2D*/
/*ENVOIE PAR ADRESSE?*/
void	free_tab(char **tab2d)
{
	int	i;

	i = 0;
	while (tab2d[i])
	{
		free(tab2d[i]);
		tab2d[i] = NULL;
		i++;
	}
/*FAUT IL FREE COMME SA?*/
	free(tab2d[i]);
	free(tab2d);
}


void	nb_player_checker(char **tab2d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab2d[i])
	{
		j = 0;
		while (tab2d[i][j])
		{
			if (tab2d[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		free_tab(tab2d);
		error_msg_map(3);
	}
}
				


void	nb_exit_checker(char **tab2d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab2d[i])
	{
		j = 0;
		while (tab2d[i][j])
		{
			if (tab2d[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		free_tab(tab2d);
		error_msg_map(4);
	}
}

void	nb_collectible_checker(char **tab2d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab2d[i])
	{
		j = 0;
		while (tab2d[i][j])
		{
			if (tab2d[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
	{
		free_tab(tab2d);
		error_msg_map(5);
	}
}
