# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 12:57:24 by marvin            #+#    #+#              #
#    Updated: 2023/02/15 17:20:32 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #
# LEAKS Checking:
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer
# leaks -atExit -- ./push_swap
#
# explications:
#
# 	1) ${MAKE} -C libft
# 		-> va dans le dossier libft et execute make
# 	2) cp ./libft/libft.a .
# 		-> copie le fichier libft.a du dossier libft dans le dossier présent .
# 	3) ${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft.a
# 		->execute gcc -Wall -Werror -Wextra -o push_swap libft.a *.o (les fichiers du dossier present!)
# 	4) ${MAKE} -C libft clean
# 		-> va dans le dossier libft et execute make clean


SRCS = 			map_errors_check/errors_msg.c \
				map_errors_check/extension_check.c \
				map_errors_check/open_error_check.c \
				map_errors_check/bidimensional_tab.c \
				map_errors_check/create_list.c \
				test_map.c \
				map_errors_check/elements_checker.c \
				map_errors_check/nbr_elements_checker.c \
				map_errors_check/map_checker.c \
				map_errors_check/free_array.c \
				map_errors_check/accessibility_check.c \
				map_errors_check/accessibility_check_utils.c \
				image_to_window.c \
				init_list.c


OBJS = ${SRCS:.c=.o}

NAME 	= so_long
CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
		${CC} ${CFLAGS} -Imlx -Imap_errors_check -c $< -o ${<:.c=.o}

all:	${NAME}

libft/libft.a: 
		${MAKE} -C ../libft

mlx/libmlx.dylib:
		${MAKE} -C mlx/

$(NAME):	${OBJS} mlx/libmlx.dylib libft/libft.a
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ../libft/libft.a mlx/libmlx.dylib
clean:
		${MAKE} -C ../libft clean
		${RM} ${OBJS}

fclean:		clean
		${MAKE} -C ../libft fclean
		${MAKE} -C mlx/ clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
