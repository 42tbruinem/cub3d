/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stringprint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:00:01 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/07 15:29:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstrfd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}
