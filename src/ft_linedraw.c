/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_linedraw.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:53:59 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 12:24:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_line_draw(t_data *data, t_dda *dda, t_line line, t_texdata tex)
{
	int		i;
	t_color	color;
	double	tex_y;

	i = 0;
	tex_y = ((line.start - data->mlx.height / 2 + line.length / 2)
			* tex.y_step) - tex.y_step;
	while (i < data->mlx.height)
	{
		if (i >= line.start && i <= line.end)
		{
			color = ft_texture_get(data, dda, tex.x,
					((int)tex_y > 0) ? (int)tex_y : 0);
			ft_mlx_pixel_to_img(data, line.x, i, color.color);
			tex_y += tex.y_step;
		}
		else if (i < line.start)
			ft_mlx_pixel_to_img(data, line.x, i, data->scene.ceiling.color);
		else if (i < data->mlx.height)
			ft_mlx_pixel_to_img(data, line.x, i, data->scene.floor.color);
		i++;
	}
}

t_line		ft_linedata(t_data *data, double dist, int x)
{
	t_line	line;

	line.x = x;
	line.length = data->mlx.height / dist;
	line.start = -line.length / 2 + data->mlx.height / 2;
	line.end = line.length / 2 + data->mlx.height / 2;
	if (line.start < 0)
		line.start = 0;
	if (line.end >= data->mlx.height)
		line.end = data->mlx.height - 1;
	return (line);
}
