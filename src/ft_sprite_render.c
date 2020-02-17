/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite_render.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:01:42 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/17 13:12:21 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite_drawy(t_data *data, t_spriterender *render, int x, int ad)
{
	int		y;
	int		d;
	char	*image;
	t_png	sprite;
	t_color	col;

	y = render->drawstart.y;
	sprite = data->scene.sprite;
	while (y < render->drawend.y)
	{
		d = (y - ad) * 256 - data->mlx.height * 128 +
			render->spriteres.y * 128;
		render->tex.y = ((d * sprite.height) / render->spriteres.y) / 256;
		image = data->scene.sprite_tex;
		image += (int)((int)render->tex.y *
			sprite.ll + ((int)render->tex.x * (sprite.bpp / 8)));
		col.color = *(unsigned int *)image;
		if (col.packed.a == 0)
			ft_mlx_pixel_to_img(data, x, y, col.color);
		y++;
	}
}

void	ft_sprite_drawx(t_data *data, t_spriterender *render,
						int spritescreen_x, int ad)
{
	int		x;

	x = render->drawstart.x;
	while (x <= render->drawend.x)
	{
		render->tex.x = (int)(256 * (x - (-render->spriteres.x / 2 +
			spritescreen_x)) * data->scene.sprite.width /
			render->spriteres.x) / 256;
		if (render->transform.y > 0 && x >= 0 && x < data->mlx.width &&
			render->transform.y < data->mapdata.dist[x])
			ft_sprite_drawy(data, render, x, ad);
		x++;
	}
}

t_vec	ft_sprite_transform(t_data *data, int i)
{
	t_vec	spritepos;
	t_vec	transform;
	double	inverse;

	spritepos.x = data->mapdata.sprites[i].pos.x + 0.5 - data->cam.pos.x;
	spritepos.y = data->mapdata.sprites[i].pos.y + 0.5 - data->cam.pos.y;
	inverse = 1.0 / (data->cam.plane.x * data->cam.dir.y -
					(data->cam.dir.x * data->cam.plane.y));
	transform.x = inverse * (data->cam.dir.y * spritepos.x
							- data->cam.dir.x * spritepos.y);
	transform.y = inverse * (-data->cam.plane.y * spritepos.x
							+ data->cam.plane.x * spritepos.y);
	return (transform);
}

void	ft_drawdata_get(t_data *data,
		t_spriterender *render, int spritescreen_x, int ad)
{
	render->drawstart.y = -render->spriteres.y / 2 + data->mlx.height / 2 + ad;
	render->drawend.y = render->spriteres.y / 2 + data->mlx.height / 2 + ad;
	if (render->drawstart.y < 0)
		render->drawstart.y = 0;
	if (render->drawend.y >= data->mlx.height)
		render->drawend.y = data->mlx.height - 1;
	render->drawstart.x = -render->spriteres.x / 2 + spritescreen_x;
	render->drawend.x = render->spriteres.x / 2 + spritescreen_x;
	if (render->drawstart.x < 0)
		render->drawstart.x = 0;
	if (render->drawend.x >= data->mlx.width)
		render->drawend.x = data->mlx.width - 1;
}

void	ft_sprite_render(t_data *data, int index)
{
	t_spriterender	render;
	int				spritescreen_x;
	int				sprite_adjust;

	render.transform = ft_sprite_transform(data, index);
	sprite_adjust = (SPRITEHEIGHT / render.transform.y);
	spritescreen_x = (int)((data->mlx.width / 2) *
					(1 + render.transform.x / render.transform.y));
	render.spriteres.y = ft_abs((int)((data->mlx.height /
						render.transform.y))) / SPRITESCALE;
	render.spriteres.x = render.spriteres.y;
	ft_drawdata_get(data, &render, spritescreen_x, sprite_adjust);
	ft_sprite_drawx(data, &render, spritescreen_x, sprite_adjust);
}
