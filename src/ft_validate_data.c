/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_data.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:16:58 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/17 11:53:37 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_validate_range(int min, int max, int nb)
{
	if (nb >= min && max >= nb)
		return (1);
	return (0);
}

int		ft_validate_type(char *str)
{
	int i;
	int j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(FILE_TYPE) - 1;
	while (str[i] && j >= 0)
	{
		if (str[i] != FILE_TYPE[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}

void	ft_validate_mapwall(t_data *data, char *field, int start)
{
	int		len;

	len = ft_strlen(field) - 1;
	while (start <= len)
	{
		if (field[start] != '1')
		{
			ft_map_del(data->mapdata.map);
			exit(ft_error(data, ERR_STR_OPENMAP, -1));
		}
		start++;
	}
}

void	ft_validate_map(t_data *data)
{
	int		y;
	char	**map;
	int		len;

	y = 0;
	len = ft_map_size(data->mapdata.map);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		exit(ft_error(data, ERR_STR_MEM, -1));
	while (y < len)
	{
		map[y] = ft_strdup(data->mapdata.map[y]);
		if (!map[y])
			exit(ft_error(data, ERR_STR_MEM, -1));
		y++;
	}
	map[y] = 0;
	if (!(ft_mapcheck(map, data->cam.pos.x, data->cam.pos.y, 100000)))
	{
		ft_map_del(map);
		exit(ft_error(data, ERR_STR_MAPERROR, -1));
	}
	ft_map_edit(data, map);
}

void	ft_validate_data(t_data *data)
{
	if (data->mlx.width == -1 || data->mlx.height == -1)
		exit(ft_error(data, ERR_STR_RES, -1));
	if (data->scene.ceiling.color == 0)
		exit(ft_error(data, ERR_STR_CEILING, -1));
	if (data->scene.floor.color == 0)
		exit(ft_error(data, ERR_STR_FLOOR, -1));
	if (data->scene.sprite.img == NULL)
		exit(ft_error(data, ERR_STR_SPRITE, -1));
	if (data->scene.walls[EAST].img == NULL)
		exit(ft_error(data, ERR_STR_TEX_EAST, -1));
	if (data->scene.walls[SOUTH].img == NULL)
		exit(ft_error(data, ERR_STR_TEX_SOUTH, -1));
	if (data->scene.walls[NORTH].img == NULL)
		exit(ft_error(data, ERR_STR_TEX_NORTH, -1));
	if (data->scene.walls[WEST].img == NULL)
		exit(ft_error(data, ERR_STR_TEX_WEST, -1));
	if (data->scene.direction == EMPTY)
		exit(ft_error(data, ERR_STR_NODIR, -1));
	ft_validate_map(data);
	ft_sprite_array(data);
	data->mapdata.dist = ft_dist_array(data);
}
