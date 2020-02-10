/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 18:38:42 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/06 16:52:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color			ft_color_init(int r, int g, int b)
{
	t_color	new;

	new.packed.r = r;
	new.packed.g = g;
	new.packed.b = b;
	return (new);
}
