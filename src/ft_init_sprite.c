/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_sprite.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:07:08 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 17:49:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_sprite_dist(t_data *data)
{
	int		i;
	t_vec	sprite;
	t_vec	pos;

	i = 0;
	while (i < data->mapdata.numsprites)
	{
		sprite.x = data->mapdata.sprites[i].pos.x + 0.5;
		sprite.y = data->mapdata.sprites[i].pos.y + 0.5;
		pos = data->cam.pos;
		data->mapdata.sprites[i].dist = ((pos.x - sprite.x) *
			(pos.x - sprite.x) + (pos.y - sprite.y) * (pos.y - sprite.y));
		i++;
	}
}

void		ft_sprite_arrayfill(t_data *data)
{
	int		y;
	int		x;
	char	**map;
	int		i;

	i = 0;
	map = data->mapdata.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
			{
				data->mapdata.sprites[i].pos = ft_coord_init(y, x);
				i++;
			}
			x++;
		}
		y++;
	}
}

void		ft_sprite_array(t_data *data)
{
	int			len;
	t_sprite	*sprites;
	int			*indices;
	int			i;

	i = 0;
	len = data->mapdata.numsprites;
	sprites = malloc(sizeof(t_sprite) * (len + 1));
	if (!sprites)
		exit(ft_error(data, ERR_STR_MEM, -1));
	data->mapdata.sprites = sprites;
	ft_sprite_arrayfill(data);
	ft_sprite_dist(data);
	indices = malloc(sizeof(t_sprite) * len);
	if (!indices)
		exit(ft_error(data, ERR_STR_MEM, -1));
	while (i < data->mapdata.numsprites)
	{
		indices[i] = i;
		i++;
	}
	data->mapdata.indices = indices;
	ft_merge_sort(data, 0, data->mapdata.numsprites - 1);
}

void		ft_init_sprite(t_data *data, char *line, int i, int linenr)
{
	int		fd;
	int		*width;
	int		*height;
	char	*path;

	width = &data->scene.sprite.width;
	height = &data->scene.sprite.height;
	if (data->scene.sprite.img != NULL)
		exit(ft_error(data, ERR_STR_DOUBLEID, linenr));
	fd = ft_texture_fd(data, line, i, &path);
	if (read(fd, (void *)0, 0) == -1)
		exit(ft_error(data, ERR_STR_FILE, linenr));
	data->scene.sprite.img = mlx_png_file_to_image(data->mlx.data, path,
													width, height);
	data->scene.sprite_tex = mlx_get_data_addr(data->scene.sprite.img,
		&data->scene.sprite.bpp, &data->scene.sprite.ll,
		&data->scene.sprite.end);
	data->mapdata.sprites = 0;
	free(path);
}
