/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:27:15 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/22 18:35:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		ft_deg2rad(double angle)
{
	return (angle * (M_PI / 180));
}

double		ft_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
