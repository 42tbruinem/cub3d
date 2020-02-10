/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:26:07 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:09:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		*ft_dist_array(t_data *data)
{
	double	*arr;

	arr = malloc(sizeof(double) * (data->mlx.width));
	if (!arr)
		exit(ft_error(data, ERR_STR_MEM, -1));
	return (arr);
}

void		ft_tex_init(char **tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tex[i] = NULL;
		i++;
	}
}

void		ft_data_mlx_init(t_data *data)
{
	data->mlx.image1 = NULL;
	data->mlx.image2 = NULL;
	data->mlx.window = NULL;
	data->mlx.width = -1;
	data->mlx.height = -1;
}

void		ft_data_init(t_data *data)
{
	ft_mlx_key_init(data);
	ft_reader_init(&data->reader);
	data->mapdata.dist = NULL;
	data->mapdata.indices = NULL;
	data->mapdata.sprites = NULL;
	data->scene.sprite_tex = NULL;
	ft_tex_init(data->scene.tex);
	data->mapdata.numsprites = 0;
	data->scene.ceiling.color = 0;
	data->scene.floor.color = 0;
	data->scene.sprite.img = NULL;
	data->scene.walls[EAST].img = NULL;
	data->scene.walls[WEST].img = NULL;
	data->scene.walls[NORTH].img = NULL;
	data->scene.walls[SOUTH].img = NULL;
	data->scene.direction = EMPTY;
	data->mapdata.map = NULL;
	data->mapdata.height = 0;
	data->mapdata.width = 0;
	data->mlx.data = mlx_init();
	ft_data_mlx_init(data);
	if (!data->mlx.data)
		exit(ft_error(data, ERR_STR_MEM, -1));
}
