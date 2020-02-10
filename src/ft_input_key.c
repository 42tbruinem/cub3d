/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_input_key.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:05:39 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 13:50:05 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mlx_exit(t_data *data)
{
	ft_freedom(data);
	return (1);
}

void	ft_mlx_key_init(t_data *data)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		data->mlx.keys[i] = 0;
		i++;
	}
}

void	ft_mlx_key_update(t_data *data, int keycode, int state)
{
	if (keycode == LEFT_ARROW)
		data->mlx.keys[ROT_L] = state;
	if (keycode == RIGHT_ARROW)
		data->mlx.keys[ROT_R] = state;
	if (keycode == D)
		data->mlx.keys[MOV_R] = state;
	if (keycode == A)
		data->mlx.keys[MOV_L] = state;
	if (keycode == W)
		data->mlx.keys[MOV_F] = state;
	if (keycode == S)
		data->mlx.keys[MOV_B] = state;
}

int		ft_mlx_keydown(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == ESCAPE)
		(void)ft_mlx_exit(data);
	ft_mlx_key_update(data, keycode, ON);
	return (0);
}

int		ft_mlx_keyup(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	ft_mlx_key_update(data, keycode, OFF);
	return (0);
}
