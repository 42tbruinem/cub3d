/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:19:06 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/27 15:02:48 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putnbr(int fd, int nb, int base)
{
	if (nb >= base)
		ft_putnbr(fd, nb / base, base);
	ft_putchar(fd, nb % base + '0');
}

int		ft_atoi(char *str, int *i)
{
	int n;
	int ret;

	n = 1;
	ret = 0;
	while ((str[*i] >= 9 && str[*i] <= 13)
			|| (str[*i] == ' ' || str[*i] == ','))
		(*i)++;
	if (str[*i] == '-')
		n = -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = ret * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (ret * n);
}

double	ft_atod(char *str, int *i)
{
	double	ret;
	int		base;
	double	tmp;
	double	n;

	base = 10;
	ret = (double)ft_atoi(str, i);
	n = (ret < 0) ? -1.0 : 1.0;
	ret *= n;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			tmp = (double)(str[*i] - '0') / base;
			ret = ret + tmp;
			(*i)++;
			base *= 10;
		}
	}
	return (ret * n);
}
