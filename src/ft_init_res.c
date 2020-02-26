/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_res.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:17:48 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 23:01:50 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_res(t_data *data, char *line, int i, int linenr)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(data->mlx.data, &max_x, &max_y);
	if (data->mlx.width == -1)
		data->mlx.width = ft_atoi(line, &i);
	else
		exit(ft_error(data, ERR_STR_DOUBLEID, linenr));
	if (data->mlx.height == -1)
		data->mlx.height = ft_atoi(line, &i);
	else
		exit(ft_error(data, ERR_STR_DOUBLEID, linenr));
	if (data->mlx.width <= 0)
		exit(ft_error(data, ERR_STR_RES, linenr));
	if (data->mlx.width > max_x && !data->bmp)
		data->mlx.width = max_x;
	if (data->mlx.height <= 0)
		exit(ft_error(data, ERR_STR_RES, linenr));
	if (data->mlx.height > max_y && !data->bmp)
		data->mlx.height = max_y;
}
