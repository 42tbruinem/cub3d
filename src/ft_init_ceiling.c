/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_ceiling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:50:04 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/18 17:47:37 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ceiling(t_data *data, char *line, int i, int linenr)
{
	int		r;
	int		g;
	int		b;

	if (data->scene.ceiling_set != 0)
		exit(ft_error(data, ERR_STR_DOUBLEID, linenr));
	while (line[i] == ' ')
		i++;
	r = ft_atoi(line, &i);
	g = ft_atoi(line, &i);
	b = ft_atoi(line, &i);
	if (ft_validate_range(0, 255, r) == 0)
		exit(ft_error(data, ERR_STR_RANGE, linenr));
	if (ft_validate_range(0, 255, g) == 0)
		exit(ft_error(data, ERR_STR_RANGE, linenr));
	if (ft_validate_range(0, 255, b) == 0)
		exit(ft_error(data, ERR_STR_RANGE, linenr));
	data->scene.ceiling.packed.r = (unsigned char)r;
	data->scene.ceiling.packed.g = (unsigned char)g;
	data->scene.ceiling.packed.b = (unsigned char)b;
	data->scene.ceiling.packed.a = (unsigned char)0;
	data->scene.ceiling_set = 1;
}
