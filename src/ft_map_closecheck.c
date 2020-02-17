/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_closecheck.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 19:14:11 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/17 11:52:51 by tbruinem      ########   odam.nl         */
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

int		ft_mapcheck(char **map, int x, int y, int maxdepth)
{
	if ((y < 0 || x < 0) || (!map[y][x] || maxdepth <= 0))
		return (0);
	if (map[y][x] == 'X' || map[y][x] == '1')
		return (1);
	if (map[y][x] != '1' && !ft_match("NSWE", map[y][x]))
		map[y][x] = 'X';
	if (ft_mapcheck(map, x - 1, y, maxdepth - 1) &&
		ft_mapcheck(map, x + 1, y, maxdepth - 1) &&
		ft_mapcheck(map, x, y - 1, maxdepth - 1) &&
		ft_mapcheck(map, x, y + 1, maxdepth - 1) &&
		ft_mapcheck(map, x - 1, y - 1, maxdepth - 1) &&
		ft_mapcheck(map, x + 1, y + 1, maxdepth - 1) &&
		ft_mapcheck(map, x - 1, y + 1, maxdepth - 1) &&
		ft_mapcheck(map, x + 1, y - 1, maxdepth - 1))
		return (1);
	return (0);
}
