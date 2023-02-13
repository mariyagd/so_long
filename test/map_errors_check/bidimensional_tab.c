/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidimensional_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:47:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/13 16:09:38 by mdanchev         ###   lausanne.ch       */
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

char	**prepare_bidimensional_tab(t_list **head)
{
	size_t		size_x;
	size_t		size_y;
	t_list		*ptr;
	char		**array;

	size_x = 0;
	size_y = 0;
	ptr = *head;
	size_x = ft_strlen(ptr->content);
	while (ptr != NULL && ft_strlen(ptr->content) == size_x)
	{
		size_y++;
		ptr = ptr->next;
	}
	if (size_y == 1 || size_y == 2 || size_y == size_x || \
			(ptr != NULL && ft_strlen(ptr->content) != size_x))
	{
		ft_lstclear(head, del);
		error_msg_one(4);
	}
	array = create_bidimensional_tab(size_y, size_x, head);
	map_checker(array, head, size_y, size_x);
	ft_lstclear(head, del);
	return (array);
}

/*TEST SIZE*/
/*
ft_printf("size_x = %d\n", size_x);
ft_printf("size_y = %d\n", size_y);
*/

/*PRINT ARRAY*/
/*
int	i = 0;
while (array[i])
{
	ft_printf("%s\n", array[i]);
	i++;
}
ft_printf("%s\n", array[i]);
*/

//LEAKS TEST: FREE ARRAY AND FREE LIST
/*
ft_lstclear(head, del);
free_array(array, size_x);
*/
