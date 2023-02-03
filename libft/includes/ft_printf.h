/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:35:31 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:25:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *last, ...);
void	ft_printf_char(char c, int fd, int *count);
void	ft_printf_str(char *s, int fd, int *count);
void	ft_printf_int(int n, int fd, int *count);
int		ft_count_int(int n);
void	ft_put_unsnbr_fd(unsigned int n, int fd);
void	ft_printf_unsint(unsigned int n, int fd, int *count);
int		ft_count_unsigned_int(unsigned int n);
void	ft_printf_address(uintptr_t n, int fd, int *count);
void	ft_printf_hexa(unsigned int n, int fd, int *count, char c);

#endif
