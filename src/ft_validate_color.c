/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_validate_color.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:05:28 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 20:13:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_validate_color_entry(t_data *data, char *line, char *errstr)
{
	size_t	len;
	size_t	commas;
	size_t	numbers;
	size_t	blocks;
	size_t	preceding_spaces;

	preceding_spaces = ft_strskipc(line, ' ');
	line = (preceding_spaces) ? line + preceding_spaces : line;
	blocks = ft_strclenb(line, ',');
	len = ft_strlencskip(line, ' ');
	commas = ft_strlenc(line, ',');
	numbers = ft_strlens(line, "0123456789");
	if ((commas + numbers != len || commas != 2) ||
		(blocks != 3 || numbers < 3))
		exit(ft_error(data, errstr, -1));
}
