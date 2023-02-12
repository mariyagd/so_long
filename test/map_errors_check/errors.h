/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:00:13 by marvin            #+#    #+#             */
/*   Updated: 2023/02/09 16:20:22 by marvin           ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ERRORS_H
# define ERRORS_H

# include "../../libft/includes/libft.h"
# include <fcntl.h>

/*ERRORS MSG*/
void	error_msg_one(int i);
void	error_msg_six(int i);
void	error_msg_map_one(int i);
void	error_msg_map_four(int i);
void	error_msg_map_seven(int i);

/*CHECK*/
void	extension_check(char *s);
void	open_error_check(int fd);

/*FREE TAB2D IF THERE IS AN ERROR*/
void	free_array(char **array, int size_x);

/*MAP ERRORS CHECKER*/
void	map_checker(char **array, t_list **head, int size_x, int size_y);
void	walls_checker(char **array, t_list **head, int size_x, int size_y);
void	nb_player_checker(char **array, t_list **head, int size_x);
void	nb_exit_checker(char **array, t_list **head, int size_x);
void	nb_collectible_checker(char **array, t_list **head, int size_x);
void	elements_checker(char **array, t_list **head, int size_x);

/*CREATE AND FILL TAB2D*/
void	prepare_bidimensional_tab(t_list **head);
void	fill_array(char **array, t_list *head);
char	**malloc_array(int size_x, int size_y);
char	**create_bidimensional_tab(int size_x, int size_y, t_list **head);
void	copy_string(char **dst, char *src);

/*MAP CHECKER*/

/*LINKED LIST*/
t_list	*get_line_into_list(int fd);
void	errors_malloc_control(int fd, int error, char **str, t_list **head);
#endif
