/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_texture_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:04:46 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/09 14:11:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_texture_fd(t_data *data, char *line, int i, char **path)
{
	int		fd;
	char	*tmp;

	while (line[i] == ' ')
		i++;
	tmp = ft_strdupc(line + i, ' ');
	if (!tmp)
		exit(ft_error(data, ERR_STR_MEM, -1));
	fd = open(tmp, O_RDONLY);
	*path = tmp;
	return (fd);
}
