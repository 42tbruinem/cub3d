/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_ceiling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:50:04 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 20:17:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_ceiling(t_data *data, char *line, int i, int linenr)
{
	int		r;
	int		g;
	int		b;
	int		start;

	if (data->scene.ceiling_set != 0)
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
		ERR_STR_CEILING);
	data->scene.ceiling.packed.r = (unsigned char)r;
	data->scene.ceiling.packed.g = (unsigned char)g;
	data->scene.ceiling.packed.b = (unsigned char)b;
	data->scene.ceiling.packed.a = (unsigned char)0;
	data->scene.ceiling_set = 1;
}
