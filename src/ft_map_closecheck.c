/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_closecheck.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 19:14:11 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 17:18:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_edit(t_data *data, char **reachable)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = data->mapdata.map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2' && reachable[y][x] != 'X')
			{
				data->mapdata.numsprites--;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int		ft_mapcheck(t_data *data, char **map, int x, int y)
{
	int l;
	int r;
	int u;
	int d;

	if (y < 0 || x < 0 || !map[y][x])
	{
		ft_map_del(map);
		exit(ft_error(data, ERR_STR_OPENMAP, -1));
	}
	if (map[y][x] == 'X' || map[y][x] == '1')
		return (1);
	if (map[y][x] != '1' && !ft_match("NSWE", map[y][x]))
		map[y][x] = 'X';
	l = ft_mapcheck(data, map, x - 1, y);
	r = ft_mapcheck(data, map, x + 1, y);
	u = ft_mapcheck(data, map, x, y - 1);
	d = ft_mapcheck(data, map, x, y + 1);
	if (l && r && u && d)
		return (1);
	ft_map_del(map);
	exit(ft_error(data, ERR_STR_OPENMAP, -1));
}
