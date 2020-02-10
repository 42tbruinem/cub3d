/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:31:20 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 13:57:02 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **input)
{
	t_data	data;
	int		fd;

	ft_data_init(&data);
	fd = ft_validate_input(&data, argc, input);
	ft_data_read(&data, fd);
	ft_validate_data(&data);
	ft_mlx_init(&data);
	ft_direction_init(&data);
	ft_raycast(&data);
	mlx_hook(data.mlx.window, KEY_PRESS_CODE, 1L << 0, &ft_mlx_keydown, &data);
	mlx_hook(data.mlx.window, KEY_RELEASE_CODE, 1L << 1, &ft_mlx_keyup, &data);
	mlx_hook(data.mlx.window, RED_BUTTON_CODE, 1L << 1, &ft_mlx_exit, &data);
	mlx_loop_hook(data.mlx.data, &ft_mlx_update, &data);
	mlx_loop(data.mlx.data);
	return (0);
}
