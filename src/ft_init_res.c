/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_res.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:17:48 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:10:38 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_res(t_data *data, char *line, int i, int linenr)
{
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
	if (data->mlx.width > MAX_WIDTH)
		data->mlx.width = MAX_WIDTH;
	if (data->mlx.height <= 0)
		exit(ft_error(data, ERR_STR_RES, linenr));
	if (data->mlx.height > MAX_HEIGHT)
		data->mlx.height = MAX_HEIGHT;
}
