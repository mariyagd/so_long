#include "../libft/includes/libft.h"
#include "errors.h" 
//#include <stdio.h>
//#include <stdlib.h>
void	error_msg(int i)
{
	if (i == 1)
	{  
		ft_printf("\033[0;31;7mError.0.01:\033[0m");
		ft_printf_fd(2, " Please enter only one argument.\n");
	}
	if (i == 2)
	{
		ft_printf("\033[0;31;7mError.0.02:\033[0m");
		ft_printf_fd(2, " Could not open the file.\n");
	}
	if (i == 3)
	{
		ft_printf("\033[0;31;7mError.0.03:\033[0m");
		ft_printf_fd(2, " Invalid file. Please enter a .ber file.\n");
	}
	if (i == 4)
	{
		ft_printf("\033[0;31;7mError.0.04:\033[0m");
		ft_printf_fd(2, " Shape error.\n");
	}
	if (i == 5)
	{
		ft_printf("\033[0;31;7mError.0.05:\033[0m");
		ft_printf_fd(2, " Shape error. Not a rectangular map.\n");
	}
	if (i == 6)
	{
		ft_printf("\033[0;31;7mError.0.06:\033[0m");
		ft_printf_fd(2, " Something happened. Could not malloc correctly.\n");
	}

	ft_printf("\n\n\033[37;7mExit program failure\033[0m\n");
	exit(1);
}

void	error_msg_map(int i)
{
	if (i == 1)
	{  
		ft_printf("\033[0;31;7mError.1.07:\033[0m");
		ft_printf_fd(2, " Map error. Error wall.\n");
	}
	if (i == 2)
	{  
		ft_printf("\033[0;31;7mError.1.08:\033[0m");
		ft_printf_fd(2, " Map error. Not an assignable character.\n");
	}
	if (i == 3)
	{  
		ft_printf("\033[0;31;7mError.1.09:\033[0m");
		ft_printf_fd(2, " Map error. Number of players is incorrect.\n");
	}
	if (i == 4)
	{  
		ft_printf("\033[0;31;7mError.1.10:\033[0m");
		ft_printf_fd(2, " Map error. Number of exits is incorrect.\n");
	}
	if (i == 5)
	{  
		ft_printf("\033[0;31;7mError.1.11:\033[0m");
		ft_printf_fd(2, " Map error. Number of collectibles is incorrect.\n");
	}
	ft_printf("\n\n\033[37;7mExit program failure\033[0m\n");
	exit(1);


}

