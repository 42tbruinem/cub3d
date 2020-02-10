/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:26:04 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 19:16:05 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_direction_rot(t_data *data, double angle)
{
	t_vec	plane;
	t_vec	dir;

	data->scene.direction += angle;
	if (data->scene.direction < 0)
		data->scene.direction += 360;
	angle = ft_deg2rad(angle);
	plane.x = data->cam.plane.x * cos(angle) + data->cam.plane.y * -sin(angle);
	plane.y = data->cam.plane.x * sin(angle) + data->cam.plane.y * cos(angle);
	dir.x = data->cam.dir.x * cos(angle) + data->cam.dir.y * -sin(angle);
	dir.y = data->cam.dir.x * sin(angle) + data->cam.dir.y * cos(angle);
	data->cam.dir = dir;
	data->cam.plane = plane;
}

void		ft_direction_init(t_data *data)
{
	double	direction;

	direction = ft_deg2rad(data->scene.direction);
	data->cam.dir.x = cos(direction);
	data->cam.plane.x = sin(direction);
	data->cam.dir.y = -sin(direction);
	data->cam.plane.y = cos(direction);
}

t_ray		ft_ray_direction(t_data *data, int x)
{
	t_ray	ray;
	double	camdir_x;
	t_vec	dir;
	t_vec	plane;

	dir = data->cam.dir;
	plane = data->cam.plane;
	camdir_x = ((2 * x / (double)data->mlx.width) - 1);
	ray.dir.x = dir.x + plane.x * camdir_x;
	ray.dir.y = dir.y + plane.y * camdir_x;
	ray.pos = data->cam.pos;
	return (ray);
}

void		ft_sprite_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mapdata.numsprites)
	{
		ft_sprite_render(data, data->mapdata.indices[i]);
		i++;
	}
}

void		ft_raycast(t_data *data)
{
	t_line		line;
	t_dda		dda;
	t_texdata	tex;
	double		*dist;
	int			x;

	x = 0;
	dist = data->mapdata.dist;
	while (x < data->mlx.width)
	{
		data->cam.ray = ft_ray_direction(data, x);
		dist[x] = ft_dist_calc(data, &dda);
		line = ft_linedata(data, dist[x], x);
		tex = ft_texdata_get(data, &dda, dist[x], line);
		ft_line_draw(data, &dda, line, tex);
		x++;
	}
	ft_sprite_loop(data);
	if (data->bmp != 0)
		ft_img_to_bmp(data);
	else
		ft_mlx_img_to_win(data);
}
