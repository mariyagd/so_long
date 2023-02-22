/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:12:24 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 13:12:26 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	extension_check(char *s)
{
	char	*s1;

	s1 = ".ber\0";
	while (*s && *s != '.')
		s++;
	if (*s == '\0')
		error_msg_one(3);
	if (ft_strlen(s) != 4)
		error_msg_one(3);
	if (ft_strncmp(s, s1, 4) != 0)
		error_msg_one(3);
}
