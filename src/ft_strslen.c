/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strslen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:09:38 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/19 12:12:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strslen(char *str, char *set)
{
	size_t	i;

	i = 0;
	while (str[i] && (!(ft_chrmatchs(str[i], set))))
		i++;
	return (i);
}
