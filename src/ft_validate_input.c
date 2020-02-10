/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 15:16:48 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:12:01 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_validate_input(t_data *data, int argc, char **input)
{
	int fd;

	data->bmp = 0;
	if (argc < 2)
		exit(ft_error(data, ERR_STR_ARG, -1));
	if (argc > 2)
	{
		if (ft_strcmp(input[2], "--save") == 1)
			exit(ft_error(data, ERR_STR_ARG, -1));
		data->bmp = open("render.bmp", O_WRONLY | O_CREAT, 0644);
	}
	fd = open(input[1], O_RDONLY);
	if (read(fd, (void *)0, 0) == -1)
		exit(ft_error(data, ERR_STR_FILE, -1));
	if (ft_validate_type(input[1]) == 0)
		exit(ft_error(data, ERR_STR_TYPE, -1));
	return (fd);
}
