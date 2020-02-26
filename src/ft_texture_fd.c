/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_texture_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:04:46 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 14:02:36 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_texture_fd(t_data *data, char *line, int i, char **path)
{
	int		fd;
	char	*tmp;
	int		n;

	while (line[i] == ' ')
		i++;
	tmp = ft_strdup(line + i);
	n = ft_strlen(tmp);
	n = (n) ? n - 1 : n;
	while (tmp[n] == ' ' && n < 0)
	{
		tmp[n] = '\0';
		n--;
	}
	if (!tmp)
		exit(ft_error(data, ERR_STR_MEM, -1));
	fd = open(tmp, O_RDONLY);
	*path = tmp;
	return (fd);
}
