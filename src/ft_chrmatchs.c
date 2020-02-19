/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrmatchs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 23:35:37 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 13:03:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	ft_chrmatchs(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i] == 0) ? 0 : 1;
}
