/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mlx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:20:13 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:11:20 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_img_to_win(t_data *data)
{
	if (data->mlx.frame % 2 == 0)
		mlx_put_image_to_window(data->mlx.data, data->mlx.window,
			data->mlx.image2, 0, 0);
	else
		mlx_put_image_to_window(data->mlx.data, data->mlx.window,
			data->mlx.image1, 0, 0);
}

void	ft_mlx_pixel_to_img(t_data *data, int x, int y, unsigned int col)
{
	char			*image;

	if (data->mlx.frame % 2 == 0)
		image = data->mlx.addr2;
	else
		image = data->mlx.addr1;
	image += (y * data->mlx.ll + (x * (data->mlx.bpp / 8)));
	*(unsigned int *)image = col;
}

void	ft_mlx_init(t_data *data)
{
	data->mlx.frame = 1;
	data->mlx.data = mlx_init();
	if (!data->mlx.data)
		exit(ft_error(data, ERR_STR_MEM, -1));
	data->mlx.window = mlx_new_window(data->mlx.data,
						data->mlx.width, data->mlx.height, "Cub3d");
	if (!data->mlx.window)
		exit(ft_error(data, ERR_STR_MEM, -1));
	data->mlx.image1 = mlx_new_image(data->mlx.data, data->mlx.width,
									data->mlx.height);
	data->mlx.image2 = mlx_new_image(data->mlx.data, data->mlx.width,
									data->mlx.height);
	if (!data->mlx.image1 || !data->mlx.image2)
		exit(ft_error(data, ERR_STR_MEM, -1));
	data->mlx.addr1 = mlx_get_data_addr(data->mlx.image1, &data->mlx.bpp,
						&data->mlx.ll, &data->mlx.endian);
	data->mlx.addr2 = mlx_get_data_addr(data->mlx.image2, &data->mlx.bpp,
						&data->mlx.ll, &data->mlx.endian);
	if (!data->mlx.addr1 || !data->mlx.addr2)
		exit(ft_error(data, ERR_STR_MEM, -1));
}
