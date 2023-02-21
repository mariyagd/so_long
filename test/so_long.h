#ifndef SO_LONG_H
# define SO_LONG_H

# include "map_errors_check/errors.h"
# include "mlx/mlx.h"

# define	SPRITE	64
# define 	ARR_UP	126
# define	W		13
# define	ARR_DWN	125
# define	S		1
# define	ARR_L	123
# define 	A		0
# define 	ARR_R	124
# define	D		2
# define	ESC		53

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
	int		flag_collect;
	int		flag_exit;
	int		mvt_count;
}			t_data;

/*INITIALISE STRUCTURE*/
void	image_window(t_data *list);
void	put_image_to_window(t_data *list, int i, int j);
void	init_list_args(t_data *list);
void	init_list_image(t_data *list);

/*EXPOSE HOOK*/
void	expose_hook_up(t_data *list, int keycode);
void	expose_hook_down(t_data *list, int keycode);
void	expose_hook_left(t_data *list, int keycode);
void	expose_hook_right(t_data *list, int keycode);

/*EVENTS AND KEY HOOK*/
void	prepare_to_exit(int keycode, t_data *list);
void	key_hook(int keycode, t_data *list);
int		funct_ptr(int key, t_data *list);
void	events(t_data *list);

/*PRINT KEY AND COUNT MOUVEMENTS*/
void	print_key(int keycode, int mvt_count);

/*CLOSE WINDOW AND FREE*/
int	close_program(t_data *list);

#endif
