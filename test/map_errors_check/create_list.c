/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:53:28 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 13:10:23 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

/*
 * error = 1
 *		--> first string could not be malloc or the map is empty
 *	error = 2
 *		--> first node could not be malloced
 *	error = 3
 *		--> node or node->content could not be malloced
 *	*/

void	errors_malloc_control(int fd, int error, char **str, t_list **head)
{
	if (error == 1)
	{
		close(fd);
		error_msg_six(7);
	}
	else if (error == 2)
		free(*str);
	else if (error == 3)
	{
		free(*str);
		ft_lstclear(head, del);
	}
	close(fd);
	error_msg_six(6);
}

void	creat_linked_list(t_list **node, t_list **head, char **str, int fd)
{
	*node = ft_lstnew(NULL);
	if (!*node)
		errors_malloc_control(fd, 3, str, head);
	ft_lstadd_back(head, *node);
}

t_list	*get_line_into_list(int fd)
{
	char	*str;
	t_list	*node;
	t_list	*head;

	str = NULL;
	str = get_next_line(fd);
	if (!str)
		errors_malloc_control(fd, 1, NULL, NULL);
	node = ft_lstnew(NULL);
	if (!node)
		errors_malloc_control(fd, 2, &str, NULL);
	head = node;
	while (str != NULL)
	{
		node->content = ft_strtrim(str, "\n");
		if (!node->content)
			errors_malloc_control(fd, 3, &str, &head);
		free(str);
		str = NULL;
		str = get_next_line(fd);
		if (str != NULL)
			creat_linked_list(&node, &head, &str, fd);
	}
	close (fd);
	return (head);
}
