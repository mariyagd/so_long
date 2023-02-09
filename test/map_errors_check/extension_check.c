/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:15:04 by marvin            #+#    #+#             */
/*   Updated: 2023/02/09 16:25:14 by marvin           ###   lausanne.ch       */
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
