/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:41:32 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 16:08:59 by marvin           ###   lausanne.ch       */
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
	if (error == 2)
		free(*str);
	if (error == 3)
	{
		free(*str);
		ft_lstclear(head, del);
	}
	close(fd);
	error_msg_six(6);
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
		{
			node = ft_lstnew(NULL);
			if (!node)
				errors_malloc_control(fd, 3, &str, &head);
			ft_lstadd_back(&head, node);
		}
	}
	close (fd);
	return (head);
}

/* TESTER DE LA FONCTION*/
/*
int	main(int ac, char **av)
{
	int	fd;
	t_list *head;


	if (ac != 2)
		error_msg(1);
	extension_check(av[1]);
	fd = open(av[1], O_RDONLY);
	open_error_check(fd);
	head = get_line_into_list(fd);


	//PRINT LA LIST
	t_list *ptr1;
	ptr1 = head;
	while (ptr1 != NULL)
	{
		ft_printf("%s\n", ptr1->content);
		ptr1 = ptr1->next;
	}

	//SUPPRESSION DE LA LISTE
	ft_lstclear(&head, del);
	return (0);
}
*/
