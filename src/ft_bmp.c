/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bmp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:30:03 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/07 15:29:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_write_color(int fd, t_color col)
{
	write(fd, &col.packed.b, 1);
	write(fd, &col.packed.g, 1);
	write(fd, &col.packed.r, 1);
}

unsigned int	ft_pixel_from_img(t_data *data, int x, int y)
{
	char			*image;
	t_color			col;

	image = data->mlx.addr1;
	image += (int)(y * data->mlx.ll + (x * (data->mlx.bpp / 8)));
	col.color = *(unsigned int *)image;
	return (col.color);
}

void			ft_zeropad(int fd, int len)
{
	int				i;
	unsigned char	c;

	c = 0x00;
	i = 0;
	while (i < len)
	{
		write(fd, &c, 1);
		i++;
	}
}

void			ft_header_write(t_data *data)
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	size;

	width = (unsigned int)data->mlx.width;
	height = (unsigned int)data->mlx.height;
	size = (4 * (width * height));
	write(data->bmp, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	write(data->bmp, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	write(data->bmp, &width, 4);
	write(data->bmp, &height, 4);
	write(data->bmp, "\x01\x00\x18\x00\x00\x00\x00\x00", 8);
	write(data->bmp, &size, 4);
	ft_zeropad(data->bmp, 16);
}

void			ft_img_to_bmp(t_data *data)
{
	int		x;
	int		y;
	t_color	packed;

	ft_header_write(data);
	y = data->mlx.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->mlx.width)
		{
			packed.color = ft_pixel_from_img(data, x, y);
			ft_write_color(data->bmp, packed);
			x++;
		}
		if ((data->mlx.width * 3) % 4 != 0)
			ft_zeropad(data->bmp, 4 - ((data->mlx.width * 3) % 4));
		y--;
	}
	close(data->bmp);
	exit(0);
}
