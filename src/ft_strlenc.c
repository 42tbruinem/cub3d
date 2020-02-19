/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlenc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:58:00 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 11:58:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		ft_strlenc(char *str, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == c)
			len++;
		i++;
	}
	return (len);
}
