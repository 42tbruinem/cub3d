/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:03:00 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/10 13:22:11 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_line(int line)
{
	if (line < 0)
		return ;
	write(2, " | Line: ", 9);
	ft_putnbr(2, line + 1, 10);
}

int		ft_error(t_data *data, char *errorstr, int line)
{
	ft_putstrfd(2, "Error\n");
	ft_putstrfd(2, errorstr);
	ft_error_line(line);
	write(2, "\n", 1);
	ft_freedom(data);
	return (1);
}
