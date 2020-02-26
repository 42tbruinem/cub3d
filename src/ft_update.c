/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_update.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 12:54:54 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 13:35:27 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_iseq(double c1, double c2)
{
	if (c1 - c2 >= -0.01 && c1 - c2 <= 0.01)
		return (1);
	return (0);
}

t_vec	ft_bumpifround(char **map, t_vec orig)
{
	t_vec	new;

	new = orig;
	if (ft_iseq(floor(orig.y), orig.y) &&
		(int)orig.y - 1 > 0 &&
		!ft_chrmatchs(map[(int)orig.y - 1][(int)orig.x], "1"))
		new.y += 0.05;
	if (ft_iseq(ceil(orig.y), orig.y) &&
		map[(int)orig.y + 1][(int)orig.x] == '1')
		new.y -= 0.05;
	if (ft_iseq(floor(orig.x), orig.x) &&
		(int)orig.x - 1 > 0 &&
		!ft_chrmatchs(map[(int)orig.y][(int)orig.x - 1], "1"))
		new.x += 0.05;
	if (ft_iseq(ceil(orig.x), orig.x) &&
		ft_chrmatchs(map[(int)orig.y][(int)orig.x + 1], "1"))
		new.x -= 0.05;
	return (new);
}

void	ft_position_update(t_data *data, t_vec incr, double speed)
{
	char	**map;
	t_vec	pos;
	t_vec	newpos;

	pos = data->cam.pos;
	map = data->mapdata.map;
	pos.x += speed * incr.x;
	pos.y += speed * incr.y;
	newpos.y = data->cam.pos.y;
	newpos.x = data->cam.pos.x;
	if (pos.y > 0 &&
		!ft_chrmatchs(map[(int)pos.y][(int)data->cam.pos.x], "1"))
		newpos.y = pos.y;
	if (pos.x > 0 &&
		!ft_chrmatchs(map[(int)data->cam.pos.y][(int)pos.x], "1"))
		newpos.x = pos.x;
	newpos = ft_bumpifround(data->mapdata.map, newpos);
	data->cam.pos = newpos;
}

int		ft_mlx_update(t_data *data)
{
	int	*key;

	key = data->mlx.keys;
	if (key[MOV_F] || key[MOV_B] || key[MOV_R] ||
		key[MOV_L] || key[ROT_R] || key[ROT_L])
	{
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
		ft_sprite_dist(data);
		ft_merge_sort(data, 0, data->mapdata.numsprites - 1);
		data->mlx.frame = (data->mlx.frame < 255) ? data->mlx.frame + 1 : 2;
		ft_raycast(data);
	}
	return (0);
}
