/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_distcalc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:55:39 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:05:35 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_side_set(int nb, int opt1, int opt2)
{
	if (nb < 0)
		return (opt1);
	return (opt2);
}

void		ft_step_init(t_cam cam, t_dda *dda)
{
	if (cam.ray.dir.x < 0.0)
	{
		dda->step.x = -1;
		dda->sidedist.x = (cam.pos.x - (int)cam.pos.x) * dda->deltadist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->sidedist.x = ((int)cam.pos.x + 1.0 - cam.pos.x) * dda->deltadist.x;
	}
	if (cam.ray.dir.y < 0)
	{
		dda->step.y = -1;
		dda->sidedist.y = (cam.pos.y - (int)cam.pos.y) * dda->deltadist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->sidedist.y = ((int)cam.pos.y + 1.0 - cam.pos.y) * dda->deltadist.y;
	}
}

void		ft_dda(t_data *data, t_dda *dda)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->sidedist.y > dda->sidedist.x)
		{
			dda->sidedist.x += dda->deltadist.x;
			dda->mappos.x += dda->step.x;
			dda->side = ft_side_set(dda->step.x, WEST, EAST);
		}
		else
		{
			dda->sidedist.y += dda->deltadist.y;
			dda->mappos.y += dda->step.y;
			dda->side = ft_side_set(dda->step.y, NORTH, SOUTH);
		}
		if (dda->mappos.y < 0 || dda->mappos.x < 0 ||
			!data->mapdata.map[dda->mappos.y][dda->mappos.x] ||
			data->mapdata.map[dda->mappos.y][dda->mappos.x] == '1')
			hit = 1;
	}
}

double		ft_dist_calc(t_data *data, t_dda *dda)
{
	double	dist;

	dda->deltadist.x = ft_abs(1.0 / (double)data->cam.ray.dir.x);
	dda->deltadist.y = ft_abs(1.0 / (double)data->cam.ray.dir.y);
	dda->mappos.x = (int)data->cam.pos.x;
	dda->mappos.y = (int)data->cam.pos.y;
	ft_step_init(data->cam, dda);
	ft_dda(data, dda);
	if (dda->side == EAST || dda->side == WEST)
		dist = (dda->mappos.x - data->cam.pos.x + (1 - dda->step.x) / 2)
		/ data->cam.ray.dir.x;
	else
		dist = (dda->mappos.y - data->cam.pos.y + (1 - dda->step.y) / 2)
		/ data->cam.ray.dir.y;
	return (dist);
}
