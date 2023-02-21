#include "so_long.h"

void	print_key(int keycode, int mvt_count)
{
	if (keycode == W)
		ft_printf("Nb mouvements = %d, key = %c\n", mvt_count, 'W'); 
	else if (keycode == ARR_UP)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "ARROW UP"); 
	else if (keycode == S)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "S"); 
	else if (keycode == ARR_DWN)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "ARROW DOWN"); 
	else if (keycode == A)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "A"); 
	else if (keycode == ARR_L)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "ARROW LEFT"); 
	else if (keycode == D)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "D"); 
	else if (keycode == ARR_R)
		ft_printf("Nb mouvements = %d, key = %s\n", mvt_count, "ARROW RIGHT");
}
