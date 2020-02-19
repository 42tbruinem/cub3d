/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlens.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:58:32 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 12:11:17 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlens(char *str, char *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_chrmatchs(str[i], set))
			len++;
		i++;
	}
	return (len);
}
