/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 13:45:08 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:10:14 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_map_size(char **map)
{
	int		len;

	len = 0;
	if (map == NULL)
		return (0);
	while (map[len])
		len++;
	return (len);
}

void		ft_map_placeplayer(t_data *data, int x)
{
	int		y;

	y = ft_map_size(data->mapdata.map);
	data->cam.pos.x = x + 0.5;
	data->cam.pos.y = y + 0.5;
}

void		ft_map_validate(t_data *data, char *str, int i, int linenr)
{
	char	mapchar;

	mapchar = str[i];
	if (ft_match("012NSEW", mapchar) == 0)
		exit(ft_error(data, ERR_STR_MAPCHAR, linenr));
	if (mapchar == '2')
		data->mapdata.numsprites++;
	if (ft_match("NSWE", mapchar) == 0)
		return ;
	if (data->scene.direction != EMPTY)
		exit(ft_error(data, ERR_STR_DOUBLEDIR, linenr));
	if (mapchar == 'N')
		data->scene.direction = DIR_N;
	if (mapchar == 'S')
		data->scene.direction = DIR_S;
	if (mapchar == 'W')
		data->scene.direction = DIR_W;
	if (mapchar == 'E')
		data->scene.direction = DIR_E;
	ft_map_placeplayer(data, i);
}

char		*ft_map_add(t_data *data, char *line, int linenr)
{
	int		len;
	char	*str;
	int		i;
	int		c;

	i = 0;
	c = 0;
	len = ft_strlencskip(line, ' ');
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		exit(ft_error(data, ERR_STR_MEM, linenr));
	while (line[c])
	{
		if (line[c] != ' ')
		{
			str[i] = line[c];
			ft_map_validate(data, str, i, linenr);
			i++;
		}
		c++;
	}
	str[i] = 0;
	return (str);
}

void		ft_init_map(t_data *data, char *line, int i, int linenr)
{
	int		len;
	char	**map;

	i = 0;
	len = ft_map_size(data->mapdata.map);
	map = malloc(sizeof(char *) * (len + 2));
	if (!map)
		exit(ft_error(data, ERR_STR_MEM, linenr));
	while (i < len)
	{
		map[i] = ft_strdup(data->mapdata.map[i]);
		if (!map[i])
			exit(ft_error(data, ERR_STR_MEM, -1));
		free(data->mapdata.map[i]);
		i++;
	}
	map[i] = ft_map_add(data, line, linenr);
	map[i + 1] = 0;
	free(data->mapdata.map);
	data->mapdata.map = map;
	data->mapdata.height++;
}
