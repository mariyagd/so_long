/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidimensional_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:53:09 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 12:53:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	fill_array(char **array, t_list *head)
{
	t_list	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (ptr != NULL)
	{
		array[i] = ft_strcpy(array[i], ptr->content);
		ptr = ptr->next;
		i++;
	}
}

char	**malloc_array(int size_y, int size_x)
{
	int		i;
	char	**array;

	i = 0;
	array = (char **)ft_calloc((size_y + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (i < size_y)
	{
		array[i] = (char *)ft_calloc((size_x + 1), sizeof(char));
		if (!array[i])
		{
			free_array(array, size_y);
			return (NULL);
		}
		i++;
	}
	return (array);
}

char	**create_bidimensional_tab(int size_y, int size_x, t_list **head)
{
	char	**array;

	array = NULL;
	array = malloc_array(size_y, size_x);
	if (!array)
	{
		ft_lstclear(head, del);
		error_msg_six(6);
	}
	fill_array(array, *head);
	return (array);
}

void	copy_string(char **dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\n')
	{
		*dst[i] = src[i];
		i++;
	}
	*dst[i] = '\0';
}
/*
 _______________________
 | 0 | 1 | 1 | 1 | \0 |
 _______________________
 | 1 | 1 | 0 | 1 | \0 |
 _______________________
 | 2 | 1 | 0 | 1 | \0  |
 _______________________
 | 3 | 1 | 0 | 1 | \0 |
 _______________________
 | 4 | 1 | 1 | 1 | \0 |
 _______________________
     | 0 | 1 | 2 | 3  |
 _______________________
 */

/*
 * I am creating an array and its copy and I send them in map_checker function.
 * The copy will be subjected to testing and will undergo modifications \
 * in flood_fill function. 
 *
 * As I want to return the original array intact, I am therefore working \
 * with a copy. If all error tests pass successfully, I free the copy \
 * and return the original array.
 * If there is an error, I free both array and copy_array, and then exit(1).
 * This is the reason why I put them both in map_checker function - so I
 * could free them before if there is an error.
 *
 * To save a few lines, I am using t_point size, which holds \
 * the size of **array on the x and y axes
 * */

char	**prepare_bidimensional_tab(t_list **head)
{
	t_point		size;
	t_list		*ptr;
	char		**array;
	char		**copy_array;

	size.x = 0;
	size.y = 0;
	ptr = *head;
	size.x = ft_strlen_int(ptr->content);
	while (ptr != NULL && ft_strlen_int(ptr->content) == size.x)
	{
		size.y++;
		ptr = ptr->next;
	}
	if (size.y == 1 || size.y == 2 || size.y == size.x || \
			(ptr != NULL && ft_strlen_int(ptr->content) != size.x))
	{
		ft_lstclear(head, del);
		error_msg_one(4);
	}
	array = create_bidimensional_tab(size.y, size.x, head);
	copy_array = create_bidimensional_tab(size.y, size.x, head);
	ft_lstclear(head, del);
	map_checker(array, copy_array, size);
	return (array);
}
