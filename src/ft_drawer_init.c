/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawer_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:29:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/24 14:30:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_drawer	ft_drawer_init(int x, int start, int end, t_color color)
{
	t_drawer	new;

	new.color = color;
	new.x = x;
	new.y_end = end;
	new.y_start = start;
	return (new);
}
