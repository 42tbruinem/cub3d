/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_floor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:05:50 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 20:17:37 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_floor(t_data *data, char *line, int i, int linenr)
{
	int		r;
	int		g;
	int		b;
	int		start;

	if (data->scene.floor_set != 0)
		exit(ft_error(data, ERR_STR_DOUBLEID, linenr));
	while (line[i] == ' ')
		i++;
	start = i;
	r = ft_atoi(line, &i);
	g = ft_atoi(line, &i);
	b = ft_atoi(line, &i);
	if (!(ft_validate_range(0, 255, r)) ||
		!(ft_validate_range(0, 255, g)) ||
		!(ft_validate_range(0, 255, b)))
		exit(ft_error(data, ERR_STR_RANGE, linenr));
	ft_validate_color_entry(data, line + start,
			ERR_STR_FLOOR);
	data->scene.floor.packed.r = (char)r;
	data->scene.floor.packed.g = (char)g;
	data->scene.floor.packed.b = (char)b;
	data->scene.floor.packed.a = (char)0;
	data->scene.floor_set = 1;
}
