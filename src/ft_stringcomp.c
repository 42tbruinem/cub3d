/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stringcomp.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:00:55 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/05 13:01:17 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcmp(char *str, char *comp)
{
	int		i;

	i = 0;
	while (str[i] && comp[i])
	{
		if (str[i] != comp[i])
			return (1);
		i++;
	}
	if (str[i] == 0 && str[i] == comp[i])
		return (0);
	return (1);
}

int		ft_match(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
