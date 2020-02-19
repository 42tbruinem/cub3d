/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_texture.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 17:56:12 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 14:41:16 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		ft_texture_get(t_data *data, t_dda *dda, int x, int y)
{
	char			*image;
	t_color			color;

	image = data->scene.tex[dda->side];
	image += (y * data->scene.walls[dda->side].ll +
			(x * (data->scene.walls[dda->side].bpp / 8)));
	color.color = *(unsigned int *)image;
	return (color);
}

double		ft_tex_y_get(t_data *data, t_dda *dda, t_line line)
{
	double	texheight;
	double	step;

	texheight = data->scene.walls[dda->side].height;
	step = 1 * texheight / line.length;
	return (step);
}

int			ft_tex_x_get(t_data *data, t_dda *dda, double dist)
{
	double	hitpos;
	double	texwidth;
	int		tex_x;

	texwidth = data->scene.walls[dda->side].width;
	if (dda->side == EAST || dda->side == WEST)
		hitpos = data->cam.pos.y + dist * data->cam.ray.dir.y;
	else
		hitpos = data->cam.pos.x + dist * data->cam.ray.dir.x;
	hitpos -= floor(hitpos);
	hitpos = 1 - hitpos;
	tex_x = (int)(hitpos * (double)texwidth);
	if ((dda->side == EAST || dda->side == WEST) && data->cam.ray.dir.x > 0)
		tex_x = texwidth - tex_x - 1;
	if ((dda->side == NORTH || dda->side == SOUTH) && data->cam.ray.dir.y < 0)
		tex_x = texwidth - tex_x - 1;
	return (tex_x);
}

t_texdata	ft_texdata_get(t_data *data, t_dda *dda, double dist, t_line line)
{
	t_texdata	tex;

	tex.x = ft_tex_x_get(data, dda, dist);
	if (tex.x < 0)
		tex.x = 0;
	tex.y_step = ft_tex_y_get(data, dda, line);
	return (tex);
}
