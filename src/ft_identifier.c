/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_identifier.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:43:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/07 16:05:36 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_identifier_parse(char *id)
{
	if (ft_match("012", id[0]))
		return (MAP);
	if (ft_strcmp(id, ID_RES) == 0)
		return (RES);
	else if (ft_strcmp(id, ID_EAST) == 0)
		return (EAST);
	else if (ft_strcmp(id, ID_WEST) == 0)
		return (WEST);
	else if (ft_strcmp(id, ID_NORTH) == 0)
		return (NORTH);
	else if (ft_strcmp(id, ID_SOUTH) == 0)
		return (SOUTH);
	else if (ft_strcmp(id, ID_FLOOR) == 0)
		return (FLOOR);
	else if (ft_strcmp(id, ID_CEILING) == 0)
		return (CEILING);
	else if (ft_strcmp(id, ID_SPRITE) == 0)
		return (SPRITE);
	else if (id[0] != '\0')
		return (INVALID);
	else
		return (EMPTY);
}

int		ft_identifier_get(char *line, int *i)
{
	char	id[3];
	int		c;

	c = 0;
	while (line[*i] == ' ')
		(*i)++;
	while (line[*i] && line[*i] != ' ' && c < 2)
	{
		id[c] = line[*i];
		(*i)++;
		c++;
	}
	id[c] = 0;
	return (ft_identifier_parse(id));
}
