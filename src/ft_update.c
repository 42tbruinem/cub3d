/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_update.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 12:54:54 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:03:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coord	ft_diff_get(t_vec orig)
{
	t_coord	diff;

	diff.x = ((orig.x - floor(orig.x) >= -0.01 &&
				orig.x - floor(orig.x) <= 0.01) ||
				(orig.x - ceil(orig.x) >= -0.01 &&
				orig.x - ceil(orig.x) <= 0.01)) ? 0 : 1;
	diff.y = ((orig.y - floor(orig.y) >= -0.01 &&
				orig.y - floor(orig.y) <= 0.01) ||
				(orig.y - ceil(orig.y) >= -0.01 &&
				orig.y - ceil(orig.y) <= 0.01)) ? 0 : 1;
	return (diff);
}

t_vec	ft_bumpifround(char **map, t_vec orig)
{
	t_vec	new;

	new = orig;
	if (ceil(orig.y) == orig.y)
		if ((ceil(orig.x) == orig.x &&
		map[(int)orig.y - 1][(int)floor(orig.x - 1)] == '1') ||
		map[(int)orig.y - 1][(int)(floor(orig.x))] == '1')
			new.y -= 0.05;
	if (ceil(orig.x) == orig.x)
		if ((ceil(orig.y) == orig.y &&
		map[(int)floor(orig.y - 1)][(int)orig.x - 1] == '1') ||
		map[(int)floor(orig.y)][(int)orig.x - 1] == '1')
			new.x += 0.05;
	return (new);
}

void	ft_position_update(t_data *data, t_vec incr, double speed)
{
	char	**map;
	t_vec	pos;

	pos = data->cam.pos;
	map = data->mapdata.map;
	pos.x += speed * incr.x;
	pos.y += speed * incr.y;
	if (pos.y > 0 && map[(int)pos.y][(int)data->cam.pos.x] != '1')
		data->cam.pos.y = pos.y;
	if (pos.x > 0 && map[(int)data->cam.pos.y][(int)pos.x] != '1')
		data->cam.pos.x = pos.x;
	data->cam.pos = ft_bumpifround(data->mapdata.map, data->cam.pos);
}

int		ft_mlx_update(t_data *data)
{
	int	*key;

	key = data->mlx.keys;
	if (key[MOV_F] || key[MOV_B] || key[MOV_R] ||
		key[MOV_L] || key[ROT_R] || key[ROT_L])
	{
		ft_sprite_dist(data);
		ft_merge_sort(data, 0, data->mapdata.numsprites - 1);
		if (data->mlx.keys[ROT_L])
			ft_direction_rot(data, -ROT_SPEED);
		if (data->mlx.keys[ROT_R])
			ft_direction_rot(data, ROT_SPEED);
		if (data->mlx.keys[MOV_R])
			ft_position_update(data, data->cam.plane, MOV_SPEED);
		if (data->mlx.keys[MOV_L])
			ft_position_update(data, data->cam.plane, -MOV_SPEED);
		if (data->mlx.keys[MOV_F])
			ft_position_update(data, data->cam.dir, MOV_SPEED);
		if (data->mlx.keys[MOV_B])
			ft_position_update(data, data->cam.dir, -MOV_SPEED);
		data->mlx.frame = (data->mlx.frame < 255) ? data->mlx.frame + 1 : 2;
		ft_raycast(data);
	}
	return (0);
}
