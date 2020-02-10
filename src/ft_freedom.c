/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freedom.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 21:06:49 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 15:00:47 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_del(char **map)
{
	int		i;
	int		len;

	len = ft_map_size(map);
	i = 0;
	while (i < len)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	ft_png_del(t_data *data, t_png *png)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (png[i].img)
			mlx_destroy_image(data->mlx.data, png[i].img);
		i++;
	}
}

void	ft_freedom(t_data *data)
{
	free(data->mapdata.dist);
	free(data->mapdata.indices);
	free(data->mapdata.sprites);
	if (data->scene.sprite.img)
		mlx_destroy_image(data->mlx.data, data->scene.sprite.img);
	if (data->scene.walls[0].img)
		ft_png_del(data, data->scene.walls);
	if (data->mapdata.map)
		ft_map_del(data->mapdata.map);
	if (data->mlx.image1)
		mlx_destroy_image(data->mlx.data, data->mlx.image1);
	if (data->mlx.image2)
		mlx_destroy_image(data->mlx.data, data->mlx.image2);
	if (data->mlx.window)
		mlx_destroy_window(data->mlx.data, data->mlx.window);
	exit(0);
}
