/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_funct.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:09:29 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/27 15:04:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_initf		ft_init_funct(int id)
{
	static const t_initf functs[] = {
		[RES] = &ft_init_res,
		[MAP] = &ft_init_map,
		[FLOOR] = &ft_init_floor,
		[CEILING] = &ft_init_ceiling,
		[SPRITE] = &ft_init_sprite,
		[NORTH] = &ft_init_north,
		[SOUTH] = &ft_init_south,
		[WEST] = &ft_init_west,
		[EAST] = &ft_init_east,
	};

	if (id != -1)
		return (functs[id]);
	return (NULL);
}
