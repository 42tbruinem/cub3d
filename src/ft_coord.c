/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_coord.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 13:01:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/05 12:38:36 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coord		ft_coord_init(int y, int x)
{
	t_coord	new;

	new.y = y;
	new.x = x;
	return (new);
}
