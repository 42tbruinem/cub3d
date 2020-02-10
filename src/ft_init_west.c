/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_west.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:12:01 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 14:18:58 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_and_exit(char *path, t_data *data, char *errstr, int linenr)
{
	free(path);
	exit(ft_error(data, errstr, linenr));
}

void		ft_init_west(t_data *data, char *line, int i, int linenr)
{
	char	*path;
	int		fd;
	int		*width;
	int		*height;

	path = NULL;
	width = &data->scene.walls[WEST].width;
	height = &data->scene.walls[WEST].height;
	if (data->scene.walls[WEST].img != NULL)
		ft_free_and_exit(path, data, ERR_STR_DOUBLEID, linenr);
	fd = ft_texture_fd(data, line, i, &path);
	if (read(fd, (void *)0, 0) == -1)
		ft_free_and_exit(path, data, ERR_STR_FILE, linenr);
	data->scene.walls[WEST].img = mlx_png_file_to_image(data->mlx.data,
							path, width, height);
	if (!data->scene.walls[WEST].img)
		ft_free_and_exit(path, data, ERR_STR_MEM, linenr);
	data->scene.tex[WEST] = mlx_get_data_addr(data->scene.walls[WEST].img,
		&data->scene.walls[WEST].bpp, &data->scene.walls[WEST].ll,
		&data->scene.walls[WEST].end);
	free(path);
}
