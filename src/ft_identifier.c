/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_identifier.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:43:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 20:18:15 by tbruinem      ########   odam.nl         */
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

char	*ft_add_to_id(char *id, char *line, int *c, int *i)
{
	if (line[*i] && *c < 2)
	{
		id[*c] = line[*i];
		(*i)++;
	}
	(*c)++;
	return (id);
}

int		ft_identifier_get(char *line, int *i)
{
	char	id[3];
	int		firstchar;
	int		secondchar;
	int		c;

	c = 0;
	while (line[*i] == ' ')
		(*i)++;
	ft_add_to_id(id, line, &c, i);
	id[c] = 0;
	firstchar = ft_identifier_parse(id);
	ft_add_to_id(id, line, &c, i);
	id[c] = 0;
	secondchar = ft_identifier_parse(id);
	if (secondchar >= 0)
		return (secondchar);
	(*i)--;
	return (firstchar);
}
