/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_east.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:11:33 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 14:18:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_and_exit(char *path, t_data *data, char *errstr, int linenr)
{
	free(path);
	exit(ft_error(data, errstr, linenr));
}

void		ft_init_east(t_data *data, char *line, int i, int linenr)
{
	char	*path;
	int		fd;
	int		*width;
	int		*height;

	path = NULL;
	width = &data->scene.walls[EAST].width;
	height = &data->scene.walls[EAST].height;
	if (data->scene.walls[EAST].img != NULL)
		ft_free_and_exit(path, data, ERR_STR_DOUBLEID, linenr);
	fd = ft_texture_fd(data, line, i, &path);
	if (read(fd, (void *)0, 0) == -1)
		ft_free_and_exit(path, data, ERR_STR_FILE, linenr);
	data->scene.walls[EAST].img = mlx_png_file_to_image(data->mlx.data,
							path, width, height);
	if (!data->scene.walls[EAST].img)
		ft_free_and_exit(path, data, ERR_STR_MEM, linenr);
	data->scene.tex[EAST] = mlx_get_data_addr(data->scene.walls[EAST].img,
		&data->scene.walls[EAST].bpp, &data->scene.walls[EAST].ll,
		&data->scene.walls[EAST].end);
	free(path);
}
