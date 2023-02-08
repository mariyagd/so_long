#ifndef ERRORS_H
# define ERRORS_H

#include "../libft/includes/libft.h"
#include <fcntl.h>

/*ERRORS*/
void	extension_check(char *s);
void	error_msg(int i);
void	error_msg_map(int i);
void	open_error_check(int fd);

/*FREE TAB2D IF THERE IS AN ERROR*/
void	free_tab(char **tab2d);

/*MAP ERRORS CHECKER*/
void	map_checker(char **tab2d, int size_x, int size_y);
void	walls_checker(char **tab2d, int size_x, int size_y);
void	nb_collectible_checker(char **tab2d);
void	nb_exit_checker(char **tab2d);
void	nb_player_checker(char **tab2d);
void	elements_checker(char **tab2d);

/*CREATE AND FILL TAB2D*/
void	prepare_bidimensional_tab(int fd, char **av);
void	fill_tab2d(char **tab2d, int fd, int size_y);
char	**malloc_tab2d(int size_x, int size_y);
char	**create_bidimensional_tab(int size_x, int size_y, char **av);
void	copy_string(char **dst, char *src);

/*MAP CHECKER*/

#endif

