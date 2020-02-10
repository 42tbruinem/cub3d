/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_south.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:12:41 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 14:18:50 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_and_exit(char *path, t_data *data, char *errstr, int linenr)
{
	free(path);
	exit(ft_error(data, errstr, linenr));
}

void		ft_init_south(t_data *data, char *line, int i, int linenr)
{
	char	*path;
	int		fd;
	int		*width;
	int		*height;

	path = NULL;
	width = &data->scene.walls[SOUTH].width;
	height = &data->scene.walls[SOUTH].height;
	if (data->scene.walls[SOUTH].img != NULL)
		ft_free_and_exit(path, data, ERR_STR_DOUBLEID, linenr);
	fd = ft_texture_fd(data, line, i, &path);
	if (read(fd, (void *)0, 0) == -1)
		ft_free_and_exit(path, data, ERR_STR_FILE, linenr);
	data->scene.walls[SOUTH].img = mlx_png_file_to_image(data->mlx.data,
							path, width, height);
	if (!data->scene.walls[SOUTH].img)
		ft_free_and_exit(path, data, ERR_STR_MEM, linenr);
	data->scene.tex[SOUTH] = mlx_get_data_addr(data->scene.walls[SOUTH].img,
		&data->scene.walls[SOUTH].bpp, &data->scene.walls[SOUTH].ll,
		&data->scene.walls[SOUTH].end);
	free(path);
}
