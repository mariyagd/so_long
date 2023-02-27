/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:16:28 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/22 13:16:31 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "errors.h"

void	open_error_check(int fd)
{
	if (fd < 0)
		error_msg_one(2);
}
