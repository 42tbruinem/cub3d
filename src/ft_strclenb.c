/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclenb.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 23:32:11 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 12:20:34 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strclenb(char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	i += ft_strskipc(str, c);
	while (str[i])
	{
		len++;
		i += ft_strclen(str + i, c);
		i += ft_strskipc(str + i, c);
	}
	return (len);
}
