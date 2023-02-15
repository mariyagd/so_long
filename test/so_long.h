#ifndef SO_LONG_H
# define SO_LONG_H

# include "map_errors_check/errors.h"
# include "mlx/mlx.h"

# define SPRITE 64

typedef struct	s_data 
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*wall;
	void	*open_sp;
	void	*collect;
	void	*player;
	void	*exit;
	char	**map;
	int		height;
	int		width;
	int		player_pos_x;
	int		player_pos_y;
	int		collect_max;
	int		collect_current;
}			t_data;

void	image_window(t_data *list, char **array);
void	put_image_to_window(t_data *list, char **array, int	i, int	j);
void	init_list_args(t_data *list, char **array);
void	init_list_image(t_data *list);

#endif
