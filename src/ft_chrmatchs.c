/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrmatchs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:10:39 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 12:10:50 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	ft_chrmatchs(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
